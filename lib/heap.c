#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
	HEAP_OK,
	HEAP_EMPTY,
	HEAP_CAPACITY_OVERFLOW,
	HEAP_INVALID_CAPACITY,
	HEAP_NULL_COMPARATOR,
	HEAP_OUT_OF_MEMORY,
} heap_err;

typedef bool (*heap_comparator)(const void *a, const void *b);

typedef struct heap_t {
	void **data_arr;
	size_t capacity, size;
	heap_comparator cmp;
} heap_t;

static void heap_swap(heap_t *h, size_t i, size_t j) {
	void *tmp = h->data_arr[i];
	h->data_arr[i] = h->data_arr[j];
	h->data_arr[j] = tmp;
}

static heap_err heap_grow(heap_t *h) {
	if (h->capacity > UINT32_MAX / 2)
		return HEAP_CAPACITY_OVERFLOW;

	h->capacity *= 2;
	void *tmp = realloc(h->data_arr, h->capacity * sizeof(*h->data_arr));
	if (tmp == NULL)
		return HEAP_OUT_OF_MEMORY;
	h->data_arr = (void **)tmp;
	return HEAP_OK;
}

static void heap_restore_up(heap_t *h, size_t node) {
	if (node == 0)
		return;
	size_t parent = (node - 1) / 2;

	if (h->cmp(h->data_arr[parent], h->data_arr[node]))
		return;

	heap_swap(h, node, parent);
	heap_restore_up(h, parent);
}

static void heap_restore_down(heap_t *h, size_t node) {
	size_t least = node;
	size_t l = 2 * node + 1;
	size_t r = 2 * node + 2;

	if (l < h->size && h->cmp(h->data_arr[l], h->data_arr[least]))
		least = l;
	if (r < h->size && h->cmp(h->data_arr[r], h->data_arr[least]))
		least = r;

	if (least == node)
		return;

	heap_swap(h, node, least);
	heap_restore_down(h, least);
}

heap_err heap_init(heap_t *h, size_t capacity, heap_comparator cmp) {
	if (cmp == NULL)
		return HEAP_NULL_COMPARATOR;
	if (capacity == 0)
		return HEAP_INVALID_CAPACITY;

	h->data_arr = (void **)malloc(sizeof(*h->data_arr) * h->capacity);
	if (h->data_arr == NULL)
		return HEAP_OUT_OF_MEMORY;

	h->capacity = capacity;
	h->cmp = cmp;
	h->size = 0;
	return HEAP_OK;
}

void heap_free(heap_t *h) {
	free(h->data_arr);
	*h = (heap_t){0};
	h->data_arr = NULL;
}

size_t heap_size(heap_t *h) { return h->size; }

void *heap_top(heap_t *h) {
	if (h->size == 0)
		return NULL;
	return h->data_arr[0];
}

heap_err heap_push(heap_t *h, void *data) {
	if (h->size == h->capacity) {
		heap_err err = heap_grow(h);
		if (err != 0)
			return err;
	}

	h->data_arr[h->size++] = data;
	heap_restore_up(h, h->size - 1);
	return HEAP_OK;
}

void *heap_pop(heap_t *h) {
	if (h->size == 0)
		return NULL;
	void *ret = heap_top(h);
	heap_swap(h, 0, h->size - 1);
	h->size--;

	if (h->size)
		heap_restore_down(h, 0);

	return ret;
}

#include <assert.h>
bool int_less(const void *a, const void *b) { return *(int *)a < *(int *)b; }

inline static void test_heap() {
	heap_t h;
	heap_init(&h, 100, int_less);

	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	heap_push(&h, data + 5);
	assert(5 == *(int *)heap_top(&h));

	heap_push(&h, data + 4);
	assert(4 == *(int *)heap_top(&h));

	heap_push(&h, data + 6);
	assert(4 == *(int *)heap_top(&h));

	heap_push(&h, data + 6);
	assert(4 == *(int *)heap_top(&h));

	heap_push(&h, data + 1);
	assert(1 == *(int *)heap_top(&h));

	heap_pop(&h);
	assert(4 == *(int *)heap_top(&h));

	heap_push(&h, data + 1);
	assert(1 == *(int *)heap_top(&h));
}

int main() { test_heap(); }
