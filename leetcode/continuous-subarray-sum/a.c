#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *vec_value_t;

typedef struct {
	uint64_t size;
	uint64_t max_size;
	vec_value_t *data;
} vec_t;

void vec_init(vec_t *self) {
	self->size = 0;
	self->max_size = 1;
	self->data = calloc(1, sizeof(vec_value_t));
	assert(self->data);
}

void vec_deinit(vec_t *self) {
	self->size = 0;
	self->max_size = 0;
	free(self->data);
}

void vec_push(vec_t *self, vec_value_t value) {
	self->data[self->size++] = value;

	if (self->size == self->max_size)
		self->data =
				realloc(self->data, (self->max_size *= 2) * sizeof(vec_value_t));
}

vec_value_t vec_pop(vec_t *self) { return self->data[--self->size]; }

uint64_t vec_size(vec_t *self) { return self->size; };

static bool vec_is_in_range(vec_t *self, uint64_t index) {
	return 0 <= index && index < self->size;
}

vec_value_t vec_get(vec_t *self, uint64_t index) {
	if (!vec_is_in_range(self, index))
		return NULL;

	return self->data[index];
}

void vec_set(vec_t *self, uint64_t index, vec_value_t value) {
	if (!vec_is_in_range(self, index))
		return;

	self->data[index] = value;
}

typedef uint64_t hash_t;
typedef void *map_value_t;

typedef struct {
	const char *key;
	uint64_t hash;
	map_value_t value;
} bucket_t;

typedef struct {
	uint64_t size;
	uint64_t max_size;
	vec_t *buckets_list;
} map_t;

void map_init(map_t *self) {
	self->size = 0;
	self->max_size = 1;
	self->buckets_list = calloc(1, sizeof(vec_t));
	assert(self->buckets_list);
	vec_init(self->buckets_list);
}

static void map_free_buckets(map_t *self, bool free_bucket) {
	for (uint64_t i = 0; i < self->max_size; ++i) {
		vec_t *buckets = self->buckets_list + i;
		if (free_bucket)
			for (uint64_t j = 0; j < vec_size(buckets); j++)
				free(vec_get(buckets, j));
		vec_deinit(buckets);
	}

	free(self->buckets_list);
}

void map_deinit(map_t *self) {
	map_free_buckets(self, true);
	self->size = 0;
	self->max_size = 0;
}

uint64_t hash(const char *s) {
	char c;
	uint64_t h = 0;

	while ((c = (*s++)))
		h = c + (h << 16) + (h << 6) - h;

	return h & (UINT64_MAX >> 1);
}

static bucket_t *find_bucket_by_hash(map_t *self, uint64_t hash) {
	vec_t *buckets = self->buckets_list + (hash % self->max_size);
	for (uint64_t i = 0; i < vec_size(buckets); ++i) {
		bucket_t *curr = vec_get(buckets, i);
		if (curr->hash == hash)
			return curr;
	}

	return NULL;
}

bool map_has(map_t *self, const char *key) {
	uint64_t h = hash(key);

	return find_bucket_by_hash(self, h);
}

void map_del(map_t *self, const char *key) {
	uint64_t h = hash(key);

	if (!map_has(self, key))
		return;

	vec_t *buckets = self->buckets_list + (h % self->max_size);
	bucket_t *bucket = find_bucket_by_hash(self, h);
	uint64_t i = 0;
	for (; i < vec_size(buckets); ++i) {
		bucket_t *curr = vec_get(buckets, i);
		vec_set(buckets, i - 1, curr);
	}
	vec_pop(buckets);
	free(bucket);
	self->size--;
}

static float map_load_factor(map_t *self) {
	return ((float)self->size) / ((float)self->max_size);
}

uint64_t map_size(map_t *self) { return self->size; }

void map_set(map_t *self, const char *key, map_value_t value);

static void map_expand(map_t *self) {
	map_t new;
	new.size = 0;
	new.max_size = self->max_size * 2;
	new.buckets_list = calloc(new.max_size, sizeof(vec_t));
	assert(new.buckets_list);
	for (uint64_t i = 0; i < new.max_size; ++i)
		vec_init(new.buckets_list + i);

	uint64_t new_max_size = self->max_size * 2;

	for (uint64_t i = 0; i < self->max_size; ++i) {
		vec_t *buckets = self->buckets_list + i;
		for (uint64_t j = 0; j < vec_size(buckets); j++) {
			bucket_t *bucket = vec_get(buckets, j);
			map_set(&new, bucket->key, bucket->value);
		}
	}

	map_deinit(self);
	*self = new;
}

map_value_t map_get(map_t *self, const char *key) {
	uint64_t h = hash(key);
	bucket_t *bucket = find_bucket_by_hash(self, h);
	return bucket->value;
}

void map_set(map_t *self, const char *key, map_value_t value) {
	uint64_t h = hash(key);

	if (map_has(self, key))
		map_del(self, key);

	while (map_load_factor(self) > 0.7)
		map_expand(self);

	vec_t *buckets = self->buckets_list + (h % self->max_size);

	bucket_t *bucket = calloc(1, sizeof(bucket_t));
	assert(bucket);
	bucket->hash = h;
	bucket->value = value;
	bucket->key = key;
	vec_push(buckets, bucket);

	++self->size;
}

bool checkSubarraySum(int *arr, int n, int k) {
	map_t m;
	map_init(&m);

	int64_t sum = 0;
	char key[n][100];
	char kk[100];
	sprintf(kk, "%lu", sum);
	map_set(&m, kk, (map_value_t)-1);
	for (int64_t i = 0; i < n; i++) {
		sum = (sum + arr[i]) % k;

		sprintf(key[i], "%lu", sum);

		if (!map_has(&m, key[i])) {
			map_set(&m, key[i], (map_value_t)i);
			continue;
		}

		int64_t last = (int64_t)map_get(&m, key[i]);

		if (i - last >= 2)
			return true;
	}

	return false;
}

void test() {
	int k = 6;
	int arr[] = {23, 2, 4, 6, 7};
	// 5 2 4 0 1
	// 5 1 5 5 0
	printf("%d\n", checkSubarraySum(arr, sizeof(arr) / sizeof(arr[0]), k));
}

void test_map() {
	map_t m;
	map_init(&m);
	map_set(&m, "key", "value");
	map_set(&m, "key1", "value");
	map_set(&m, "key2", "value");
	map_set(&m, "key3", "value");
	assert(map_has(&m, "key"));
	assert(!map_has(&m, "key9"));

	map_set(&m, "key", "value");
	assert(strcmp(map_get(&m, "key"), "value") == 0);

	map_del(&m, "key");
	assert(!map_has(&m, "key"));
}

void test_map2() {
	map_t m;
	map_init(&m);
	char key[] = "key-.......................";

	for (int64_t i = 0; i < 1; i++) {
		sprintf(key, "key-%ld", i);
		map_set(&m, key, (map_value_t)i);
		assert((int64_t)map_get(&m, key) == i);
	}
}

void test_vec() {
	vec_t v;
	vec_init(&v);
	for (uint64_t i = 0; i < 100; i++) {
		vec_push(&v, (void *)i);
		assert((uint64_t)vec_get(&v, i) == i);
	}
}

void custom_test() {
	map_t m;
	map_init(&m);
	map_set(&m, "0", (void *)-1);
	map_set(&m, "5", (void *)0);
	assert(map_has(&m, "5"));
	map_set(&m, "1", (void *)1);
	assert(map_has(&m, "1"));
	assert(map_has(&m, "5"));
	map_set(&m, "5", (void *)2);
	assert(map_has(&m, "1"));
	assert(map_has(&m, "5"));
	assert(map_has(&m, "5"));
	map_set(&m, "5", (void *)3);
	assert(map_has(&m, "5"));
	map_set(&m, "0", (void *)4);
}

int main() {
	test_vec();
	test_map();
	test_map2();
	test();
	custom_test();
}
