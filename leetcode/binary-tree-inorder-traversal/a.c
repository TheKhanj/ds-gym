#include <stdlib.h>

typedef struct {
	int size;
	int max_size;
	int *data;
} vec_t;

void vec_init(vec_t *self) {
	self->size = 0;
	self->max_size = 1;
	self->data = malloc(sizeof(int));
}

void vec_push(vec_t *self, int a) {
	self->data[self->size++] = a;
	if (self->size == self->max_size)
		self->data = realloc(self->data, sizeof(int) * (self->max_size *= 2));
}

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

void dfs(node_t *node, vec_t *v) {
	if (!node)
		return;
	dfs(node->left, v);
	vec_push(v, node->val);
	dfs(node->right, v);
}

int *inorderTraversal(node_t *root, int *returnSize) {
	vec_t v;
	vec_init(&v);
	dfs(root, &v);

	*returnSize = v.size;
	return v.data;
}
