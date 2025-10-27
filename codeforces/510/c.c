#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

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
	int index;
	char c;
	vec_t adj;

	int visited;
	int max_path;
} node_t;

void node_init(node_t *this, char c, int index) {
	this->c = c;
	this->index = index;
	vec_init(&this->adj);

	this->visited = 0;
	this->max_path = 0;
}

void node_free(node_t *this) { vec_free(&this->adj); }

void node_connect(node_t *u, node_t *v) {
	// printf("%c -> %c\n", u->c, v->c);

	vec_push(&u->adj, v);
}

int node_max_path_cmp(const void *a, const void *b) {
	const node_t *x = a, *y = b;
	return -x->max_path + y->max_path;
}

int is_in_path(node_t **path, int len, node_t *match) {
	for (int i = 0; i < len; i++)
		if (path[i] == match)
			return 1;
	return 0;
}

int node_dfs(node_t *this, node_t **path, size_t len) {
	path[len++] = this;
	this->visited = 1;

	for (size_t i = 0; i < vec_size(&this->adj); i++) {
		node_t *next = vec_get(&this->adj, i);

		if (is_in_path(path, len, next))
			return 1;

		if (!next->visited) {
			int has_loop = node_dfs(next, path, len);
			if (has_loop)
				return 1;
		}

		this->max_path = MAX(next->max_path + 1, this->max_path);
	}
	// printf("dfs: %c, len: %lu, max_path: %d\n", this->c, len, this->max_path);

	return 0;
}

int str_connect(node_t *nodes, char *a, char *b) {
	size_t len_a = strlen(a), len_b = strlen(b), i = 0;
	for (; i < len_a && i < len_b && a[i] == b[i]; i++) {
	}
	if (i == len_a || i == len_b)
		return len_a <= len_b;

	char x = a[i], y = b[i];

	node_connect(nodes + x - 'a', nodes + y - 'a');
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	char s[n][101];
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);

	node_t nodes[26];
	for (int i = 0; i < 26; i++)
		node_init(nodes + i, 'a' + i, i);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			char *a = s[i], *b = s[j];

			int possible = str_connect(nodes, a, b);
			if (!possible) {
				printf("Impossible\n");
				goto defer;
			}
		}

	for (int i = 0; i < 26; i++) {
		node_t *node = nodes + i;
		if (node->visited)
			continue;
		node_t *path[26];
		int has_loop = node_dfs(node, path, 0);
		if (has_loop) {
			printf("Impossible\n");
			goto defer;
		}
	}

	qsort(nodes, 26, sizeof(nodes[0]), node_max_path_cmp);

	// for (int i = 0; i < 26; i++)
	// 	printf("%c max_path: %d, visited: %d\n", nodes[i].c, nodes[i].max_path,
	// 				 nodes[i].visited);
	for (int i = 0; i < 26; i++)
		printf("%c", nodes[i].c);
	printf("\n");

defer:
	for (int i = 0; i < 26; i++)
		node_free(nodes + i);
	return 0;
}
