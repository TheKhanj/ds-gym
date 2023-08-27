#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 1e5 + 10;

typedef struct heap_t heap_t;
typedef struct heap_node_t heap_node_t;

struct heap_node_t {
	int index;
	int data;
};

struct heap_t {
	int size;
	heap_node_t *nodes;
	bool (*cmp)(int a, int b);
};

void heap_init(heap_t *h, bool (*cmp)(int a, int b)) {
	h->size = 0;
	h->nodes = malloc(sizeof(heap_node_t) * MAX_N);
	h->cmp = cmp;

	for (int i = 0; i < MAX_N; ++i) {
		h->nodes[i].index = i;
	}
}

void heap_node_swap_data(heap_node_t *node1, heap_node_t *node2) {
	const int tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

heap_node_t *heap_node_get_parent(heap_t *h, heap_node_t *node) {
	bool is_root = node->index == 0;
	if (is_root) {
		return NULL;
	}

	return h->nodes + (node->index - 1) / 2;
}

void heap_restore_up(heap_t *h, heap_node_t *node) {
	heap_node_t *parent = heap_node_get_parent(h, node);
	if (parent == NULL) {
		return;
	}

	if (h->cmp(parent->data, node->data)) {
		return;
	}

	heap_node_swap_data(parent, node);
	heap_restore_up(h, parent);
}

void heap_insert(heap_t *h, int x) {
	heap_node_t *node = h->nodes + h->size++;
	node->data = x;

	heap_restore_up(h, node);
}

heap_node_t *heap_get_root(heap_t *h) {
	assert(h->size > 0);

	return h->nodes;
}

int heap_get_extreme(heap_t *h) {
	heap_node_t *root = heap_get_root(h);

	return root->data;
}

heap_node_t *heap_node_get_by_index(heap_t *h, int index) {
	if (index < 0 || index >= h->size) {
		return NULL;
	}

	return h->nodes + index;
}

void heap_restore_down(heap_t *h, heap_node_t *node) {
	heap_node_t *extreme = node;
	heap_node_t *left = heap_node_get_by_index(h, 2 * node->index + 1);
	heap_node_t *right = heap_node_get_by_index(h, 2 * node->index + 2);

	if (left != NULL && !h->cmp(extreme->data, left->data)) {
		extreme = left;
	}

	if (right != NULL && !h->cmp(extreme->data, right->data)) {
		extreme = right;
	}

	if (extreme == node) {
		return;
	}

	heap_node_swap_data(extreme, node);
	heap_restore_down(h, extreme);
}

int heap_remove_extreme(heap_t *h) {
	heap_node_t *root = heap_get_root(h);
	const int ret = root->data;
	heap_node_t *last = h->nodes + --h->size;

	heap_node_swap_data(root, last);
	heap_restore_down(h, root);

	return ret;
}

void balance_heaps(heap_t *left_heap, heap_t *right_heap) {
	while (left_heap->size - right_heap->size > 1) {
		const int removed = heap_remove_extreme(left_heap);
		heap_insert(right_heap, removed);
	}
	while (left_heap->size < right_heap->size) {
		const int removed = heap_remove_extreme(right_heap);
		heap_insert(left_heap, removed);
	}
}

bool max_cmp(int a, int b) { return a >= b; }

bool min_cmp(int a, int b) { return a <= b; }

void solve_solution() {
	heap_t left_heap, right_heap;

	heap_init(&left_heap, max_cmp);
	heap_init(&right_heap, min_cmp);

	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		if (n == -1) {
			const int extreme = heap_remove_extreme(&left_heap);
			printf("%d\n", extreme);

			balance_heaps(&left_heap, &right_heap);
		} else {
			if (right_heap.size > 0 && heap_get_extreme(&right_heap) <= n) {
				heap_insert(&right_heap, n);
			} else {
				heap_insert(&left_heap, n);
			}

			balance_heaps(&left_heap, &right_heap);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve_solution();
	}
}
