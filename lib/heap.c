#include <stdint.h>
#include <stdlib.h>

typedef enum {
	HEAP_OK,
	HEAP_EMPTY,
	HEAP_OVERFLOW,
	HEAP_EMPTY_CAPACITY,
	HEAP_NULL_COMPARATOR,
	HEAP_MEMORY_OVERFLOW,
} heap_err;

typedef int (*heap_comparator)(const void *a, const void *b);

typedef struct heap_t {
	void **data_arr;
	uint32_t capacity, size;
	heap_comparator cmp;
} heap_t;

static void heap_swap(heap_t *h, uint32_t i, uint32_t j) {
	void *tmp = h->data_arr[i];
	h->data_arr[i] = h->data_arr[j];
	h->data_arr[j] = tmp;
}
static void heap_restore_up(heap_t *h, uint32_t node) {
	if (node == 0)
		return;
	uint32_t parent = (node - 1) / 2;

	if (h->cmp(h->data_arr[parent], h->data_arr[node]))
		return;

	heap_swap(h, node, parent);
	heap_restore_up(h, parent);
}

static void heap_restore_down(heap_t *h, uint32_t node) {
	uint32_t least = node;
	uint32_t l = 2 * node + 1;
	uint32_t r = 2 * node + 2;

	if (l < h->size && h->cmp(h->data_arr[l], h->data_arr[least]))
		least = l;
	if (r < h->size && h->cmp(h->data_arr[r], h->data_arr[least]))
		least = r;

	if (least == node)
		return;

	heap_swap(h, node, least);
	heap_restore_down(h, least);
}

heap_err heap_init(heap_t *h, uint32_t capacity, heap_comparator cmp) {
	if (cmp == NULL)
		return HEAP_NULL_COMPARATOR;
	if (capacity == 0)
		return HEAP_EMPTY_CAPACITY;

	h->capacity = capacity;
	h->cmp = cmp;
	h->data_arr = (void **)malloc(sizeof(void *) * h->capacity);
	if (h->data_arr == NULL)
		return HEAP_MEMORY_OVERFLOW;
	h->size = 0;
	return HEAP_OK;
}
void heap_free(heap_t *h) {
	free(h->data_arr);
	h->data_arr = NULL;
}

uint32_t heap_size(heap_t *h) { return h->size; }

void *heap_top(heap_t *h) {
	if (h->size == 0)
		return NULL;
	return h->data_arr[0];
}

heap_err heap_push(heap_t *h, void *data) {
	if (h->size == h->capacity) {
		if (h->capacity > UINT32_MAX / 2)
			return HEAP_OVERFLOW;
		h->capacity *= 2;
		void *tmp = realloc(h->data_arr, h->capacity * sizeof(void *));
		if (tmp == NULL)
			return HEAP_MEMORY_OVERFLOW;
		h->data_arr = tmp;
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

	heap_restore_down(h, 0);

	return ret;
}

#ifdef TEST
#	include <assert.h>
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
#endif
