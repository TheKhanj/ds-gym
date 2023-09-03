#define __USE_MINGW_ANSI_STDIO 0

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SQRT = 10000;

typedef struct set_data_t {
	char *s;
	int count;
} set_data_t;

typedef struct set_t {
	set_data_t arr[(int)1e5 + 10];
	int arr_size;

	set_data_t buffer[(int)1e5 + 10];
	int buffer_size;
} set_t;

void set_init(set_t *s) {
	s->arr_size = 0;
	s->buffer_size = 0;
}

void set_data_init(set_data_t *data, char *s) {
	data->count = 1;
	data->s = s;
}

int set_data_cmp(const void *d1, const void *d2) {
	return strcmp(((set_data_t *)d1)->s, ((set_data_t *)d2)->s);
}

void set_sort(set_t *s) {
	qsort(s->arr, s->arr_size, sizeof(s->arr[0]), set_data_cmp);
}

void set_data_copy_from(set_data_t *a, set_data_t *b) {
	a->count = b->count;
	a->s = b->s;
}

void set_unbuffer(set_t *s) {
	for (int i = 0; i < s->buffer_size; ++i) {
		set_data_t *in_buffer = &s->buffer[i];
		set_data_t *in_array = &s->arr[s->arr_size++];
		set_data_copy_from(in_array, in_buffer);
	}

	s->buffer_size = 0;
	set_sort(s);
}

void set_insert(set_t *s, char *string) {
	set_data_t *data = &s->buffer[s->buffer_size++];
	set_data_init(data, string);

	if (s->buffer_size >= SQRT) {
		set_unbuffer(s);
	}
}

typedef struct binary_search_cmp_t binary_search_cmp_t;

struct binary_search_cmp_t {
	set_t *set;
	char *desired;
	bool (*is_ok)(binary_search_cmp_t *, int pos);
};

int binary_search(int l, int r, binary_search_cmp_t *cmp) {
	if (l == r - 1) {
		return l;
	}

	int mid = (l + r) / 2;
	if (cmp->is_ok(cmp, mid)) {
		return binary_search(mid, r, cmp);
	}

	return binary_search(l, mid, cmp);
}

bool bs_is_ok(binary_search_cmp_t *this, int pos) {
	set_data_t *data = &this->set->arr[pos];
	return strcmp(this->desired, data->s) >= 0;
}

set_data_t *set_find(set_t *s, char *string) {
	set_data_t *found = NULL;

	if (s->arr_size > 0) {
		binary_search_cmp_t cmp = {.desired = string, .set = s, .is_ok = bs_is_ok};
		int pos = binary_search(0, s->arr_size, &cmp);
		found = &s->arr[pos];
	}

	if (found != NULL && strcmp(found->s, string) == 0) {
		return found;
	}

	for (int i = 0; i < s->buffer_size; i++) {
		set_data_t *buff = &s->buffer[i];
		if (strcmp(buff->s, string) == 0) {
			return buff;
		}
	}
	return NULL;
}

void set_debug(set_t *s, int test) {
	printf("test %d: \n", test);
	printf("size: %d\n", s->arr_size);
	for (int i = 0; i < s->arr_size; i++) {
		set_data_t *x = &s->arr[i];
		printf("%s\n", x->s);
	}
	printf("----\n");
}

int main() {
	int n;
	scanf("%d", &n);

	set_t set;
	set_init(&set);

	for (int i = 0; i < n; i++) {
		char *s = malloc(sizeof(char *) * 40);
		scanf("%s", s);
		const int size = strlen(s);
		set_data_t *exists = set_find(&set, s);

		if (exists == NULL) {
			printf("OK\n");
			set_insert(&set, s);
		} else {
			printf("%s%d\n", s, exists->count);
			exists->count++;
		}

		// set_debug(&set, i);
	}
}
