#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct heap_t heap_t;
typedef struct heap_node_t heap_node_t;
typedef bool (*heap_compare_function)(int, int);

bool max_cmp(int a, int b) { return a >= b; }

bool min_cmp(int a, int b) { return a <= b; }

int min_cmp2(const void *a, const void *b) { return *(int *)a - *(int *)b; }

struct heap_node_t {
	int data;
	int index;
};

struct heap_t {
	int size;
	// don't overflow from initial init size
	heap_node_t *nodes;
	int capacity;
	heap_compare_function cmp;
};

void heap_init(heap_t *h, heap_compare_function cmp) {
	h->size = 0;
	h->cmp = cmp;
	h->capacity = 1;
	h->nodes = malloc(h->capacity * sizeof(heap_node_t));
}

heap_node_t *heap_get_root(heap_t *h) {
	assert(h->size > 0);

	return h->nodes;
}

int heap_get_extreme(heap_t *h) { return heap_get_root(h)->data; }

void heap_node_swap_data(heap_node_t *node1, heap_node_t *node2) {
	int tmpData = node1->data;

	node1->data = node2->data;
	node2->data = tmpData;
}

heap_node_t *heap_get_node_by_index(heap_t *h, int index) {
	if (index < 0 || index >= h->size) {
		return NULL;
	}

	return h->nodes + index;
}

heap_node_t *heap_node_get_parent(heap_t *h, heap_node_t *node) {
	if (node->index == 0) {
		return NULL;
	}

	return heap_get_node_by_index(h, (node->index - 1) / 2);
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

heap_node_t *heap_node_get_left_child(heap_t *h, heap_node_t *node) {
	return heap_get_node_by_index(h, node->index * 2 + 1);
}

heap_node_t *heap_node_get_right_child(heap_t *h, heap_node_t *node) {
	return heap_get_node_by_index(h, node->index * 2 + 2);
}

void heap_restore_down(heap_t *h, heap_node_t *node) {
	heap_node_t *extreme_of_all_three = node;
	heap_node_t *left = heap_node_get_left_child(h, node);
	heap_node_t *right = heap_node_get_right_child(h, node);

	if (left != NULL && !h->cmp(extreme_of_all_three->data, left->data)) {
		extreme_of_all_three = left;
	}

	if (right != NULL && !h->cmp(extreme_of_all_three->data, right->data)) {
		extreme_of_all_three = right;
	}

	if (extreme_of_all_three == node) {
		return;
	}

	heap_node_swap_data(extreme_of_all_three, node);
	heap_restore_down(h, extreme_of_all_three);
}

void heap_insert(heap_t *h, int data) {
	heap_node_t *node = h->nodes + h->size;
	node->data = data;
	node->index = h->size++;

	if (h->size == h->capacity) {
		h->capacity *= 2;
		h->nodes = realloc(h->nodes, h->capacity * sizeof(h->nodes[0]));
	}

	heap_restore_up(h, h->nodes + h->size - 1);
}

void heap_debug(heap_t *h, char *prefix) {
	printf("%s\n", prefix);
	printf("size: %d\n", h->size);
	printf("capacity: %d\n", h->capacity);
	for (int i = 0; i < h->size; i++) {
		printf("%d ", h->nodes[i].data);
	}
	printf("\n");
	printf("-----\n");
}

int heap_remove_extreme(heap_t *h) {
	heap_node_t *root = heap_get_root(h);
	int ret = root->data;
	heap_node_t *last = h->nodes + --h->size;

	heap_node_swap_data(last, root);
	heap_restore_down(h, root);

	return ret;
}

typedef struct solution_t solution_t;

struct solution_t {
	heap_t left_heap, right_heap;
};

void solution_init(solution_t *s) {
	heap_init(&s->left_heap, max_cmp);
	heap_init(&s->right_heap, min_cmp);
}

void solution_balance_heaps(solution_t *s) {
	while (s->left_heap.size > s->right_heap.size + 1) {
		const int extreme = heap_remove_extreme(&s->left_heap);
		heap_insert(&s->right_heap, extreme);
	}

	while (s->left_heap.size < s->right_heap.size) {
		const int extreme = heap_remove_extreme(&s->right_heap);
		heap_insert(&s->left_heap, extreme);
	}
}

void solution_insert(solution_t *s, int x) {
	if (s->right_heap.size != 0 && x >= heap_get_extreme(&s->right_heap)) {
		heap_insert(&s->right_heap, x);
	} else {
		heap_insert(&s->left_heap, x);
	}

	solution_balance_heaps(s);
}

int solution_pop_median(solution_t *s) {
	int left_max = heap_remove_extreme(&s->left_heap);
	solution_balance_heaps(s);

	return left_max;
}

// #define AUTO_TEST
#ifdef AUTO_TEST

int get_median(int *arr, int sz) {
	qsort(arr, sz, sizeof(int), min_cmp2);
	return arr[(sz - 1) / 2];
}

void debug_median(int *arr, int sz) {
	int median = get_median(arr, sz);
	printf("median: %d\n", median);
	for (int i = 0; i < sz; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n-----\n");
}

int main() {
	solution_t s;
	solution_init(&s);

	int arr[5000];
	int sz = 0;

	time_t current_time;
	time(&current_time);
	srand(current_time);
	for (int i = 0; i < 5000; i++) {
		int x = rand() % 2;
		if (sz == 0 || x == 0) {
			int y = rand() % 100;
			solution_insert(&s, y);
			// printf("y: %d\n", y);
			arr[sz++] = y;
		} else {
			int expected_median = get_median(arr, sz);
			assert(solution_pop_median(&s) == expected_median);
			sz--;
			arr[(sz) / 2] = arr[sz];
		}
		// debug_median(arr, sz);
		// heap_debug(&s.left_heap, "left heap");
		// heap_debug(&s.right_heap, "right heap");
	}
}
#else

#	ifdef MANUAL_HEAP_TEST

int main() {
	heap_t h;
	heap_init(&h, min_cmp);
	heap_insert(&h, 10);
	heap_insert(&h, 2);
	heap_insert(&h, 22);
	assert(heap_get_extreme(&h) == 2);
	assert(heap_get_extreme(&h) == 2);
	assert(heap_get_extreme(&h) == 2);
	assert(heap_remove_extreme(&h) == 2);
	assert(heap_get_extreme(&h) == 10);
	heap_insert(&h, 11);
	assert(heap_get_extreme(&h) == 10);
	heap_insert(&h, 10);
	assert(heap_get_extreme(&h) == 10);
	heap_insert(&h, 9);
	assert(heap_get_extreme(&h) == 9);
	assert(heap_remove_extreme(&h) == 9);
	assert(heap_get_extreme(&h) == 10);
	assert(heap_remove_extreme(&h) == 10);
	assert(heap_get_extreme(&h) == 10);
	assert(heap_remove_extreme(&h) == 10);
	assert(heap_get_extreme(&h) == 11);
	assert(heap_remove_extreme(&h) == 11);
}
#	else
#		ifdef AUTO_HEAP_TEST

int get_min_index(int *arr, int sz) {
	int minIndex = 0;
	for (int i = 0; i < sz; ++i) {
		if (arr[minIndex] > arr[i]) {
			minIndex = i;
		}
	}
	return minIndex;
}

int main() {
	int arr[50000];
	int sz = 0;

	heap_t h;
	heap_init(&h, min_cmp);

	for (int x; x < 50000; x++) {
		int op = rand() % 100;
		if (sz == 0 || op == 1) {
			int value = rand();
			heap_insert(&h, value);
			arr[sz++] = value;
		} else {
			const int actualMin = heap_remove_extreme(&h);

			int min = get_min_index(arr, sz);
			assert(actualMin == arr[min]);
			arr[min] = arr[--sz];
		}

		if (sz != 0) {
			assert(heap_get_extreme(&h) == arr[get_min_index(arr, sz)]);
		}
	}
}
#		else
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solution_t s;
		solution_init(&s);
		int x;
		while (true) {
			scanf("%d", &x);
			if (x == 0) {
				break;
			}

			if (x == -1) {
				printf("%d\n", solution_pop_median(&s));
				continue;
			}

			solution_insert(&s, x);
		}
	}
}
#		endif
#	endif
#endif
