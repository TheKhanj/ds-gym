#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void **arr;
	size_t size, capacity;
} vec_t;

void vec_init(vec_t *v) {
	v->size = 0;
	v->capacity = 1;
	v->arr = (void **)malloc(sizeof(*v->arr) * v->capacity);
}
void vec_free(vec_t *v) { free(v->arr); }

static void vec_grow(vec_t *v) {
	v->capacity *= 2;
	v->arr = (void **)realloc(v->arr, sizeof(*v->arr) * v->capacity);
}

void vec_push(vec_t *v, void *data) {
	if (v->size == v->capacity)
		vec_grow(v);

	v->arr[v->size++] = data;
}

void *vec_get(vec_t *v, size_t index) { return v->arr[index]; }

size_t vec_size(vec_t *v) { return v->size; }

typedef struct {
	vec_t adj, w;
} node_t;

void node_init(node_t *node) {
	vec_init(&node->adj);
	vec_init(&node->w);
}

void node_free(node_t *node) {
	vec_free(&node->adj);
	vec_free(&node->w);
}

void node_connect(node_t *u, node_t *v, uint64_t *w) {
	vec_push(&u->adj, v);
	vec_push(&u->w, w);

	vec_push(&v->adj, u);
	vec_push(&v->w, w);
}

typedef bool (*heap_comparator)(void *a, void *b);

typedef struct {
	void **arr;
	size_t size, capacity;
	heap_comparator cmp;
} heap_t;

void heap_init(heap_t *h, heap_comparator cmp) {
	h->capacity = 1;
	h->size = 0;
	h->arr = (void **)malloc(sizeof(*h->arr) * h->capacity);
	h->cmp = cmp;
}
void heap_free(heap_t *h) { free(h->arr); }

void heap_grow(heap_t *h) {
	h->capacity *= 2;
	h->arr = (void **)realloc(h->arr, sizeof(*h->arr) * h->capacity);
}

static void heap_node_swap(heap_t *h, size_t i, size_t j) {
	void *tmp = h->arr[i];
	h->arr[i] = h->arr[j];
	h->arr[j] = tmp;
}

void heap_restore_up(heap_t *h, size_t i) {
	if (i == 0)
		return;
	size_t par = (i - 1) / 2;

	if (h->cmp(h->arr[par], h->arr[i]))
		return;

	heap_node_swap(h, i, par);
	heap_restore_up(h, par);
}

void heap_push(heap_t *h, void *data) {
	if (h->size == h->capacity)
		heap_grow(h);
	h->arr[h->size++] = data;
	heap_restore_up(h, h->size - 1);
}

bool heap_empty(heap_t *h) { return h->size == 0; }
void *heap_top(heap_t *h) { return h->arr[0]; }

static void heap_restore_down(heap_t *h, size_t i) {
	size_t l = 2 * i + 1, r = 2 * i + 2;
	size_t s = i;

	if (l < h->size && h->cmp(h->arr[l], h->arr[s]))
		s = l;
	if (r < h->size && h->cmp(h->arr[r], h->arr[s]))
		s = r;
	if (s == i)
		return;

	heap_node_swap(h, i, s);
	heap_restore_down(h, s);
}

void *heap_pop(heap_t *h) {
	void *top = heap_top(h);
	heap_node_swap(h, 0, --h->size);
	heap_restore_down(h, 0);

	return top;
}

typedef struct {
	size_t index;
	uint64_t d;
} pair_t;

void pair_init(pair_t *p, size_t index, uint64_t d) {
	p->index = index;
	p->d = d;
}

bool pair_less(void *a, void *b) { return ((pair_t *)a)->d < ((pair_t *)b)->d; }

void rev_print(size_t *parent, size_t curr) {
	if (curr != 0)
		rev_print(parent, parent[curr]);

	printf("%zu ", curr + 1);
}

void print_path(size_t n, size_t *parent) {
	size_t dst = n - 1;
	if (parent[dst] == SIZE_MAX) {
		printf("-1\n");
		return;
	}

	rev_print(parent, dst);
	printf("\n");
}

void dijkstra(size_t n, size_t m, node_t *nodes) {
	heap_t h;
	heap_init(&h, pair_less);

	uint64_t dist[n];
	size_t src = 0, parent[n];

	for (size_t i = 0; i < n; i++)
		dist[i] = UINT64_MAX / 2, parent[i] = SIZE_MAX;

	dist[src] = 0;
	pair_t pairs[m + n];
	size_t pairs_len = 0;

	pair_init(pairs + pairs_len, src, 0);
	heap_push(&h, pairs + pairs_len++);

	while (!heap_empty(&h)) {
		pair_t *top = (pair_t *)heap_pop(&h);
		size_t curr = top->index;
		// printf("visiting curr %lu\n", curr + 1);

		uint64_t curr_dist = top->d;

		// Ignore an outdated heap entry.
		if (curr_dist != dist[curr])
			continue;

		for (size_t i = 0; i < vec_size(&nodes[curr].adj); i++) {
			node_t *next_node = (node_t *)vec_get(&nodes[curr].adj, i);
			size_t next = (size_t)(next_node - nodes);
			uint64_t w = *(uint64_t *)vec_get(&nodes[curr].w, i);

			if (dist[curr] + w >= dist[next])
				continue;

			dist[next] = dist[curr] + w;
			parent[next] = curr;
			pair_init(pairs + pairs_len, next, dist[next]);
			heap_push(&h, pairs + pairs_len++);
		}
	}

	print_path(n, parent);

	heap_free(&h);
}

bool int_less(void *a, void *b) { return *(int *)a < *(int *)b; }

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int arr_min(int *arr, int i, int j) {
	int min = arr[i];
	while (i < j) {
		min = MIN(min, arr[i]);
		i++;
	}
	return min;
}

void test_heap() {
	heap_t h;
	heap_init(&h, int_less);
	//                          *
	//           0  1  2  3  4  5  6  7
	int arr[] = {9, 1, 2, 5, 4, 7, 4, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 6; i++) {
		heap_push(&h, arr + i);
		assert(*(int *)heap_top(&h) == arr_min(arr, 0, i + 1));
	}
	int top;
	top = *(int *)heap_pop(&h);
	assert(top == 1);
	top = *(int *)heap_pop(&h);
	assert(top == 2);
	top = *(int *)heap_pop(&h);
	assert(top == 4);
	top = *(int *)heap_pop(&h);
	assert(top == 5);
	top = *(int *)heap_pop(&h);
	assert(top == 7);

	for (int i = 6; i < n; i++) {
		heap_push(&h, arr + i);
		assert(*(int *)heap_top(&h) == MIN(9, arr_min(arr, 6, i + 1)));
	}

	top = *(int *)heap_pop(&h);
	assert(top == 3);
	top = *(int *)heap_pop(&h);
	assert(top == 4);
	top = *(int *)heap_pop(&h);
	assert(top == 9);
}

void solve() {
	size_t n, m;
	scanf("%zu %zu", &n, &m);
	node_t nodes[n];
	for (size_t i = 0; i < n; i++)
		node_init(nodes + i);

	uint64_t w[m];
	for (size_t i = 0; i < m; i++) {
		size_t a, b;
		scanf("%zu %zu %" SCNu64, &a, &b, w + i);
		a--, b--;
		node_connect(nodes + a, nodes + b, w + i);
	}

	dijkstra(n, m, nodes);
	for (size_t i = 0; i < n; i++)
		node_free(nodes + i);
}

int main() {
	// test_heap();
	solve();
}
