#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "result.h"

typedef enum {
	HEAP_OK,
	HEAP_EMPTY,
	HEAP_OVERFLOW,
	HEAP_EMPTY_CAPACITY
} heap_err;
typedef bool (*heap_comparator)(const void *a, const void *b);

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
RESULT_TYPE(uint32_t, heap_err, heap_node);
static result_heap_node_t heap_node_parent(heap_t *h, uint32_t node) {
	if (node == 0)
		return heap_node_err(HEAP_OVERFLOW);
	return heap_node_ok((node - 1) / 2);
}
static result_heap_node_t heap_node_left_child(heap_t *h, uint32_t node) {
	uint32_t index = 2 * node + 1;
	if (index >= h->size)
		return heap_node_err(HEAP_OVERFLOW);
	return heap_node_ok(index);
}
static result_heap_node_t heap_node_right_child(heap_t *h, uint32_t node) {
	uint32_t index = 2 * node + 2;
	if (index >= h->size)
		return heap_node_err(HEAP_OVERFLOW);
	return heap_node_ok(index);
}
static void heap_restore_up(heap_t *h, uint32_t node) {
	result_heap_node_t parent = heap_node_parent(h, node);
	if (parent.err != 0)
		return;

	if (h->cmp(h->data_arr[parent.value], h->data_arr[node]))
		return;

	heap_swap(h, node, parent.value);
	heap_restore_up(h, parent.value);
}

static void heap_restore_down(heap_t *h, uint32_t node) {
	result_heap_node_t l = heap_node_left_child(h, node);
	result_heap_node_t r = heap_node_right_child(h, node);

	uint32_t least = node;
	if (l.err == 0 && h->cmp(h->data_arr[l.value], h->data_arr[least]))
		least = l.value;
	if (r.err == 0 && h->cmp(h->data_arr[r.value], h->data_arr[least]))
		least = r.value;

	if (least == node)
		return;

	heap_swap(h, node, least);
	heap_restore_down(h, least);
}

// capacity is the initial capacity, it dynamically grows
heap_err heap_init(heap_t *h, uint32_t capacity, heap_comparator cmp) {
	if (capacity == 0)
		return HEAP_EMPTY_CAPACITY;

	h->capacity = capacity;
	h->cmp = cmp;
	h->data_arr = (void **)malloc(sizeof(void *) * h->capacity);
	h->size = 0;
	return HEAP_OK;
}
void heap_free(heap_t *h) { free(h->data_arr); }

uint32_t heap_size(heap_t *h) { return h->size; }

void *heap_top(heap_t *h) { return h->data_arr[0]; }

void heap_push(heap_t *h, void *data) {
	if (h->size == h->capacity) {
		h->capacity *= 2;
		h->data_arr = (void **)realloc(h->data_arr, h->capacity * sizeof(void *));
	}

	h->data_arr[h->size++] = data;
	heap_restore_up(h, h->size - 1);
}

void *heap_pop(heap_t *h) {
	void *ret = heap_top(h);
	heap_swap(h, 0, h->size - 1);
	h->size--;

	heap_restore_down(h, 0);

	return ret;
}

// tests
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
