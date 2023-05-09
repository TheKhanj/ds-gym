#define __USE_MINGW_ANSI_STDIO 0

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct operation operation_t;
typedef struct heap_node heap_node_t;
typedef struct heap heap_t;
typedef bool (*heap_compare_function)(void *data1, void *data2);

const int32_t RANDOM_NUMBER = 123;

enum operation_type { INSERT, REMOVE_MIN, GET_MIN };

struct operation {
	enum operation_type type;
	int32_t params;
};

operation_t ans[3 * (int)1e5 + 10];
size_t ans_size = 0;

inline static void operation_init(operation_t *operation,
																	enum operation_type type, int32_t params) {
	operation->type = type;
	operation->params = params;
}

inline static void operation_init_from_stdin(operation_t *operation) {
	char type[10];
	scanf("%s", type);

	if (!strcmp(type, "insert")) {
		operation->type = INSERT;
		scanf("%d", &operation->params);
	} else if (!strcmp(type, "getMin")) {
		operation->type = GET_MIN;
		scanf("%d", &operation->params);
	} else if (!strcmp(type, "removeMin")) {
		operation->type = REMOVE_MIN;
		operation->params = 0;
	} else {
		exit(127);
	}
}

inline static void operation_print(operation_t *operation) {
	if (operation->type == INSERT) {
		printf("insert %d\n", operation->params);
	} else if (operation->type == GET_MIN) {
		printf("getMin %d\n", operation->params);
	} else if (operation->type == REMOVE_MIN) {
		printf("removeMin\n");
	}
}

struct heap_node {
	int32_t index;
	void *data;
};

inline static void heap_node_swap_data(heap_node_t *node1, heap_node_t *node2) {
	void *original_node1_data = node1->data;
	node1->data = node2->data;
	node2->data = original_node1_data;
}

struct heap {
	int32_t size;
	heap_node_t *nodes;
	heap_compare_function cmp;
};

inline static void heap_init(heap_t *heap, size_t size,
														 heap_compare_function cmp) {
	heap->size = 0;
	heap->nodes = (heap_node_t *)malloc(size * sizeof(heap_node_t));
	heap->cmp = cmp;
}

inline static heap_node_t *heap_get_node_by_index(heap_t *heap, int32_t index) {
	if (index >= heap->size || index < 0) {
		return NULL;
	}

	return heap->nodes + index;
}

inline static heap_node_t *heap_get_left_node(heap_t *heap, heap_node_t *node) {
	const int32_t index = node->index * 2 + 1;

	return heap_get_node_by_index(heap, index);
}

inline static heap_node_t *heap_get_right_node(heap_t *heap,
																							 heap_node_t *node) {
	const int32_t index = node->index * 2 + 2;

	return heap_get_node_by_index(heap, index);
}

inline static heap_node_t *heap_get_parent_node(heap_t *heap,
																								heap_node_t *node) {
	const int32_t index = (node->index - 1) / 2;

	return heap_get_node_by_index(heap, node->index == 0 ? -1 : index);
}

inline static void heap_restore_up(heap_t *heap, heap_node_t *node) {
	heap_node_t *parent = heap_get_parent_node(heap, node);

	if (parent == NULL) {
		return;
	}

	if (heap->cmp(parent->data, node->data)) {
		return;
	}

	heap_node_swap_data(parent, node);

	return heap_restore_up(heap, parent);
}

inline static void heap_restore_down(heap_t *heap, heap_node_t *node) {
	heap_node_t *smallest = node;

	heap_node_t *left_child = heap_get_left_node(heap, node);
	heap_node_t *right_child = heap_get_right_node(heap, node);

	if (left_child != NULL && !heap->cmp(smallest->data, left_child->data)) {
		smallest = left_child;
	}

	if (right_child != NULL && !heap->cmp(smallest->data, right_child->data)) {
		smallest = right_child;
	}

	if (smallest == node) {
		return;
	}

	heap_node_swap_data(node, smallest);
	heap_restore_down(heap, smallest);
}

inline static void heap_insert(heap_t *heap, void *data) {
	heap_node_t *node = heap->nodes + heap->size++;
	node->data = data;
	node->index = heap->size - 1;

	heap_restore_up(heap, node);
}

inline static int32_t heap_get_size(heap_t *heap) { return heap->size; }

inline static void *heap_get_min(heap_t *heap) {
	if (heap->size == 0) {
		return NULL;
	}

	return heap->nodes[0].data;
}

inline static void heap_remove_min(heap_t *heap) {
	heap_node_t *root = heap->nodes;
	heap_node_t *last = heap->nodes + --heap->size;

	heap_node_swap_data(root, last);
	heap_restore_down(heap, root);
}

inline static void heap_single_node_debug(heap_t *heap, heap_node_t *node) {
	printf("(node_index) %d\n", node->index);
	printf("(node_data) %d\n", *(int32_t *)node->data);

	heap_node_t *left = heap_get_left_node(heap, node);
	heap_node_t *right = heap_get_right_node(heap, node);

	printf("(left_node_index) ");
	if (left == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", left->index);
	}

	printf("(right_node_index) ");
	if (right == NULL) {
		printf("NULL\n");
	} else {
		printf("%d\n", right->index);
	}
}

inline static void heap_debug(heap_t *heap) {
	printf("(heap_size) %d\n", heap->size);

	for (int i = 0; i < heap->size; i++) {
		heap_node_t *node = heap->nodes + i;
		heap_single_node_debug(heap, node);
		printf("\n");
	}
	printf("---\n");
}

inline static void handle_insert_operation(heap_t *heap,
																					 operation_t *operation) {
	operation_init(ans + ans_size++, operation->type, operation->params);

	heap_insert(heap, &ans[ans_size - 1].params);
}

inline static void handle_remove_min_operation(heap_t *heap,
																							 operation_t *operation) {
	bool is_empty = heap_get_size(heap) == 0;
	if (is_empty) {
		operation_init(ans + ans_size++, INSERT, RANDOM_NUMBER);

		heap_insert(heap, &ans[ans_size - 1].params);
	}

	operation_init(ans + ans_size++, operation->type, operation->params);

	heap_remove_min(heap);
}

inline static void handle_get_min_operation(heap_t *heap,
																						operation_t *operation) {
	const int32_t expected_value = operation->params;

	while (heap_get_size(heap) != 0 &&
				 *(int32_t *)heap_get_min(heap) < expected_value) {
		operation_init(ans + ans_size++, REMOVE_MIN, 0);

		heap_remove_min(heap);
	}

	if (heap_get_size(heap) == 0 ||
			*(int32_t *)heap_get_min(heap) != expected_value) {
		operation_init(ans + ans_size++, INSERT, expected_value);

		heap_insert(heap, &ans[ans_size - 1].params);
	}

	operation_init(ans + ans_size++, GET_MIN, expected_value);

	assert(*(int32_t *)heap_get_min(heap) == expected_value);
	const int32_t min = *(int32_t *)heap_get_min(heap);
}

inline static void handle_operation(heap_t *heap, operation_t *operation) {
	if (operation->type == INSERT) {
		handle_insert_operation(heap, operation);
	} else if (operation->type == REMOVE_MIN) {
		handle_remove_min_operation(heap, operation);
	} else if (operation->type == GET_MIN) {
		handle_get_min_operation(heap, operation);
	}
}

bool cmp(void *a, void *b) { return *(int32_t *)a < *(int32_t *)b; }

inline static void test_heap() {
	heap_t heap;
	heap_init(&heap, 100, cmp);

	int32_t data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	heap_insert(&heap, data + 5);
	assert(5 == *(int32_t *)heap_get_min(&heap));

	heap_insert(&heap, data + 4);
	assert(4 == *(int32_t *)heap_get_min(&heap));

	heap_insert(&heap, data + 6);
	assert(4 == *(int32_t *)heap_get_min(&heap));

	heap_insert(&heap, data + 6);
	assert(4 == *(int32_t *)heap_get_min(&heap));

	heap_insert(&heap, data + 1);
	assert(1 == *(int32_t *)heap_get_min(&heap));

	heap_remove_min(&heap);
	assert(4 == *(int32_t *)heap_get_min(&heap));

	heap_insert(&heap, data + 1);
	assert(1 == *(int32_t *)heap_get_min(&heap));
}

inline static void solve() {
	int32_t n;
	scanf("%d", &n);

	operation_t operations[n];

	heap_t heap;
	heap_init(&heap, 2 * n, cmp);

	for (int32_t i = 0; i < n; i++) {
		operation_init_from_stdin(operations + i);

		operation_t *operation = operations + i;
		handle_operation(&heap, operation);
	}
	printf("%ld\n", ans_size);

	for (int32_t i = 0; i < ans_size; i++) {
		operation_print(ans + i);
	}
}

int32_t main() { solve(); }
