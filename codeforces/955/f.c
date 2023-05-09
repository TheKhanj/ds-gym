#define __USE_MINGW_ANSI_STDIO 0

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DP_SIZE 30
#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x > y ? y : x)

typedef struct node node_t;
typedef struct vec vec_t;
typedef void *vec_data_t;

struct vec {
	int32_t max_size;
	int32_t size;
	vec_data_t *data;
};

static void vec_init(vec_t *vec) {
	vec->max_size = 1;
	vec->size = 0;
	vec->data = malloc(sizeof(vec_data_t) * vec->max_size);
}

static void vec_push(vec_t *vec, vec_data_t data) {
	vec->data[vec->size++] = data;

	if (vec->size == vec->max_size) {
		vec->max_size *= 2;
		vec->data = realloc(vec->data, sizeof(vec_data_t) * vec->max_size);
	}
}

struct node {
	int32_t index;
	node_t *parent;
	vec_t adj;
	int32_t max_height;
	bool vis;

	int64_t max_k[DP_SIZE];
	int64_t max_max_k[DP_SIZE];
};

static void node_init(node_t *node, int32_t index) {
	node->index = index;
	node->parent = NULL;
	node->max_height = 1;
	node->vis = false;
	vec_init(&node->adj);

	for (int32_t i = 0; i < DP_SIZE; i++) {
		node->max_k[i] = 0;
		node->max_max_k[i] = 0;
	}
}

static inline int32_t cmp(const void *a, const void *b) {
	return *(int32_t *)b - *(int32_t *)a;
}

static void node_fill_max_k(node_t *node) {
	for (int32_t i = 1; i < DP_SIZE; i++) {
		int32_t arr[node->adj.size];
		int32_t arr_size = 0;

		for (int32_t j = 0; j < node->adj.size; j++) {
			node_t *adj = node->adj.data[j];

			if (adj != node->parent) {
				arr[arr_size++] = adj->max_k[i - 1];
			}
		}

		qsort(arr, arr_size, sizeof(int32_t), cmp);

		int32_t dp_value = 0;
		for (int32_t j = 0; j < arr_size; j++) {
			int32_t count = j + 1;
			int32_t curr = arr[j];

			dp_value = MAX(dp_value, MIN(curr, count));
		}

		node->max_k[i] = dp_value;
	}
}

static void node_fill_max_max_k(node_t *node) {
	for (int32_t i = 0; i < DP_SIZE; i++) {
		node->max_max_k[i] = node->max_k[i];
	}

	for (int32_t i = 0; i < node->adj.size; i++) {
		node_t *adj = node->adj.data[i];
		if (adj == node->parent) {
			continue;
		}

		for (int32_t j = 0; j < DP_SIZE; j++) {

			node->max_max_k[j] = MAX(node->max_max_k[j], adj->max_max_k[j]);
		}
	}
}

static int64_t node_calculate_addition(node_t *node) {
	int64_t ret = 0;
	int64_t prev_max_k = 1;
	for (int64_t i = DP_SIZE - 1; i >= 0;) {
		int64_t max_k = node->max_max_k[i];
		int64_t prev_i = i;

		while (i >= 0 && max_k == node->max_max_k[i]) {
			i--;
		}

		if (max_k == 0 || max_k == 1) {
			prev_max_k = 1;
			continue;
		}

		int64_t count = max_k - prev_max_k;
		int64_t sum = prev_i + 1;

		int64_t total = count * sum;

		ret += total;
		prev_max_k = max_k;
	}

	ret += node->max_height;
	return ret;
}

static int64_t dfs(node_t *node, int32_t n) {
	int64_t ret = 0;

	assert(node->vis == false);
	node->vis = true;
	node->max_height = 1;
	node->max_k[0] = n;

	int32_t children = 0;

	for (int32_t i = 0; i < node->adj.size; i++) {
		node_t *adj = node->adj.data[i];

		if (adj->vis == true) {
			continue;
		}
		children++;
		adj->parent = node;

		ret += dfs(adj, n);

		node->max_height = MAX(node->max_height, adj->max_height + 1);
	}

	if (children == 0) {
		return n;
	}

	node_fill_max_k(node);
	node_fill_max_max_k(node);
	return ret + node_calculate_addition(node);
}

static void debug_node(node_t *node) {
	printf("node (%d):\n", node->index + 1);
	printf("	max_height: %d\n", node->max_height);

	printf("	");
	for (int32_t i = 0; i < DP_SIZE; i++) {
		printf("%" PRId64 " ", node->max_k[i]);
	}
	printf("\n");

	printf("	");
	for (int32_t i = 0; i < DP_SIZE; i++) {
		printf("%" PRId64 " ", node->max_max_k[i]);
	}
	printf("\n");
}

static void debug_tree(node_t *nodes, int32_t n) {
	for (int32_t i = 0; i < n; i++) {
		node_t *node = nodes + i;
		debug_node(node);
	}
}

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	node_t nodes[n];
	for (int32_t i = 0; i < n; i++) {
		node_t *node = nodes + i;
		node_init(node, i);
	}

	for (int32_t i = 0; i < n - 1; i++) {
		int32_t u, v;
		scanf("%d %d", &u, &v);

		u--;
		v--;

		vec_push(&nodes[u].adj, nodes + v);
		vec_push(&nodes[v].adj, nodes + u);
	}

	int64_t ans = dfs(nodes, n);

	printf("%" PRId64, ans);
}
