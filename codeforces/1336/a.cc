#include <assert.h>
#include <set>
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

	u->visited = false;
	u->parent = NULL;

	u->depth = 0;
	u->subtree = 0;
	u->children = 0;

	u->envoy = 0;
	u->children_envoy = 0;

	vec_init(&u->adj);
}

void node_connect(node_t *u, node_t *v) { vec_push(&u->adj, v); }

int node_is_leaf(node_t *u) { return u->children == u->children_envoy; }

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

typedef struct node_comparator {
	bool operator()(const node_t *a, const node_t *b) const {
		return node_value(a) < node_value(b);
	}
} node_comparator;

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

	std::multiset<node_t *, node_comparator> st;
	for (int i = 0; i < n; i++)
		if (node_is_leaf(nodes + i))
			st.insert(nodes + i);

	long long ans = 0;
	while (k--) {
		assert(st.size());
		auto last = (--st.end());
		auto top = *last;
		ans += node_value(top);

		top->envoy = 1;
		st.erase(last);

		if (top->parent) {
			top->parent->children_envoy++;
			if (node_is_leaf(top->parent))
				st.insert(top->parent);
		}
	}

	printf("%lld\n", ans);
}
