#include <stdio.h>
#include <stdlib.h>

typedef struct vec_t {
	size_t size, capacity;
	void **data;
} vec_t;

void vec_init(vec_t *this) {
	this->size = 0;
	this->capacity = 1;
	this->data = malloc(this->capacity * sizeof(void *));
}

void vec_free(vec_t *this) {
	free(this->data);
	this->data = NULL;
	this->capacity = 0;
	this->size = 0;
}

void vec_push(vec_t *this, void *value) {
	this->data[this->size++] = value;

	if (this->size == this->capacity) {
		this->capacity *= 2;
		this->data = realloc(this->data, this->capacity * sizeof(void *));
	}
}

void *vec_get(vec_t *this, int i) { return this->data[i]; }
size_t vec_size(vec_t *this) { return this->size; }

typedef struct node_t {
	int has_cat;
	vec_t adj;
	int visited;
	int index;
} node_t;

void node_init(node_t *this, int index, int has_cat) {
	this->index = index;
	this->has_cat = has_cat;
	vec_init(&this->adj);

	this->visited = 0;
}

void node_free(node_t *this) { vec_free(&this->adj); }

void node_connect(node_t *u, node_t *v) {
	vec_push(&u->adj, v);
	vec_push(&v->adj, u);
}

int node_is_leaf(node_t *this) {
	if (this->index == 0)
		return vec_size(&this->adj) == 0;

	return vec_size(&this->adj) == 1;
}

int node_dfs(node_t *this, int m, int consec) {
	this->visited = 1;
	if (this->has_cat)
		consec++;
	else
		consec = 0;

	if (consec > m)
		return 0;

	if (node_is_leaf(this))
		return 1;

	int ret = 0;
	for (size_t i = 0; i < vec_size(&this->adj); i++) {
		node_t *next = vec_get(&this->adj, i);

		if (next->visited)
			continue;

		ret += node_dfs(next, m, consec);
	}

	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	node_t nodes[n];

	for (int i = 0; i < n; i++) {
		int has_cat;
		scanf("%d", &has_cat);
		node_init(nodes + i, i, has_cat);
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		node_connect(nodes + u, nodes + v);
	}

	int ans = node_dfs(nodes, m, 0);
	printf("%d\n", ans);

	for (int i = 0; i < n; i++)
		node_free(nodes + i);
}
