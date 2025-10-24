#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vec_t {
	size_t capacity, size;
	void **data;
} vec_t;

void vec_init(vec_t *vec) {
	vec->capacity = 1;
	vec->size = 0;
	vec->data = (void **)malloc(vec->capacity * sizeof(void *));
}

void vec_push(vec_t *vec, void *value) {
	vec->data[vec->size++] = value;
	if (vec->size == vec->capacity) {
		vec->capacity *= 2;
		vec->data = (void **)realloc(vec->data, vec->capacity * sizeof(void *));
	}
}

void *vec_get(vec_t *vec, size_t i) { return vec->data[i]; }

void vec_free(vec_t *vec) {
	free(vec->data);
	vec->data = NULL, vec->size = 0, vec->capacity = 0;
}

size_t vec_size(vec_t *vec) { return vec->size; }

typedef struct node_t node_t;
typedef struct node_t {
	int index;
	int visited;

	node_t *parent;

	int depth;
	int children;
	int subtree;

	int envoy;
	int children_envoy;

	vec_t adj;
} node_t;

void node_init(node_t *u, int index) {
	u->index = index;

	u->visited = 0;
	u->parent = NULL;

	u->depth = 0;
	u->subtree = 0;
	u->children = 0;

	u->envoy = 0;
	u->children_envoy = 0;

	vec_init(&u->adj);
}

void node_free(node_t *u) { vec_free(&u->adj); }

void node_connect(node_t *u, node_t *v) { vec_push(&u->adj, v); }

int node_value(const node_t *u) { return u->depth - u->subtree + 1; }

void node_dfs(node_t *u) {
	u->visited = 1;

	u->children = 0;
	u->subtree = 1;
	for (size_t i = 0; i < vec_size(&u->adj); i++) {
		node_t *v = (node_t *)vec_get(&u->adj, i);
		if (v->visited)
			continue;

		v->parent = u;
		v->depth = u->depth + 1;
		node_dfs(v);

		u->children++;
		u->subtree += v->subtree;
	}
}

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	node_t nodes[n];
	for (int i = 0; i < n; i++)
		node_init(nodes + i, i);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		node_connect(nodes + u, nodes + v);
		node_connect(nodes + v, nodes + u);
	}
	node_dfs(nodes);

	int values[n];
	for (int i = 0; i < n; i++)
		values[i] = node_value(nodes + i);
	qsort(values, n, sizeof(values[0]), cmp);
	long long ans = 0;
	for (int i = 0; i < k; i++)
		ans += values[i];

	printf("%lld\n", ans);

	for (int i = 0; i < n; i++)
		node_free(nodes + i);
}
