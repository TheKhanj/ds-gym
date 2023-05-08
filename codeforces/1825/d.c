#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int64_t mod = 1e9 + 7;

typedef struct vec_t {
	size_t max_size;
	size_t size;
	void **arr;
} vec_t;

static void vec_init(vec_t *vec) {
	vec->max_size = 1;
	vec->size = 0;
	vec->arr = malloc(1 * sizeof(void *));
}

static void vec_push(vec_t *vec, void *data) {
	vec->arr[vec->size++] = data;

	if (vec->size == vec->max_size) {
		vec->max_size *= 2;
		vec->arr = realloc(vec->arr, vec->max_size * sizeof(void *));
	}
}

typedef struct node_t {
	int32_t index;
	bool vis;
	vec_t adj;
	struct node_t *parent;
	int32_t sub_tree_size;
} node_t;

static void node_init(node_t *node, int32_t index) {
	node->index = index;
	vec_init(&node->adj);
	node->vis = false;
	node->parent = NULL;
	node->sub_tree_size = 1;
}

static void node_add_adjacent(node_t *self, node_t *adj) {
	vec_push(&self->adj, adj);
}

static bool node_is_parent_of(node_t *a, node_t *b) { return b->parent == a; }

static int64_t node_get_direction_size(node_t *node, node_t *adj,
									   int64_t total_nodes) {
	if (node_is_parent_of(node, adj)) {
		return adj->sub_tree_size;
	}

	return total_nodes - node->sub_tree_size;
}

static int64_t multiply(int64_t a, int64_t b) {
	return ((a % mod) * (b % mod)) % mod;
}

static int64_t add(int64_t a, int64_t b) { return (a + b) % mod; }

static int64_t subtract(int64_t a, int64_t b) {
	return ((a % mod) - (b % mod) + mod) % mod;
}

static int64_t power(int64_t a, int64_t b) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a;
	}

	int64_t half = power(a, b / 2);
	return multiply(multiply(half, half), b % 2 == 0 ? 1 : a);
}

static int64_t divide(int64_t a, int64_t b) {
	return multiply(a, power(b, mod - 2));
}

static void dfs(node_t *node) {
	node->vis = true;
	for (int32_t i = 0; i < node->adj.size; i++) {
		node_t *adj = node->adj.arr[i];
		if (adj->vis == true) {
			continue;
		}

		dfs(adj);
		adj->parent = node;
		node->sub_tree_size += adj->sub_tree_size;
	}
}

static void solve(int64_t n, int64_t k, node_t *nodes) {
	if (k == 1 || k == 3) {
		printf("1\n");
		return;
	}

	dfs(&nodes[0]);

	int64_t ans = 0;

	for (int32_t i = 0; i < n; i++) {
		node_t *node = nodes + i;
		int64_t this_node_size = n - 1;
		int64_t tmp = n >= 2 ? ((n - 2) * (n - 1) / 2) % mod : 0;
		this_node_size = add(tmp, this_node_size);

		for (int32_t j = 0; j < node->adj.size; j++) {
			node_t *adj = node->adj.arr[j];
			int64_t size = node_get_direction_size(node, adj, n);

			this_node_size =
				subtract(this_node_size, (size * (size - 1) / 2) % mod);
		}

		ans = add(this_node_size, ans);
	}

	printf("%" PRId64 "\n", divide(ans, (n * (n - 1)) / 2) % mod);
}

static void init_nodes(node_t *nodes, size_t n) {
	for (int32_t i = 0; i < n; i++) {
		node_init(&nodes[i], i);
	}
}

static void get_input(node_t *nodes, size_t n) {
	for (int32_t i = 0; i < n - 1; i++) {
		int32_t u, v;
		scanf("%d %d", &u, &v);

		--u;
		--v;

		node_add_adjacent(&nodes[u], &nodes[v]);
		node_add_adjacent(&nodes[v], &nodes[u]);
	}
}

static void test_vec() {
	vec_t vec;
	vec_init(&vec);

	for (int i = 0; i < 1000; i++) {
		int32_t *value = malloc(sizeof(int32_t));
		*value = i;

		vec_push(&vec, value);
	}

	for (int i = 0; i < 1000; i++) {
		assert(*(int32_t *)vec.arr[i] == i);
	}

	assert(vec.size == 1000);
	assert(vec.max_size == 1024);
}

static void test_power() {
	for (int32_t i = 0, expected = 1; i < 10; i++, expected *= 2) {
		const int64_t ans = power(2, i);
		assert(ans == expected);
	}
}

int32_t main() {
	int64_t n, k;
	scanf("%" SCNd64 " %" SCNd64, &n, &k);

	node_t nodes[n];
	init_nodes(nodes, n);
	get_input(nodes, n);

	solve(n, k, nodes);
}
