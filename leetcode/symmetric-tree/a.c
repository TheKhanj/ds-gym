#include <stdbool.h>

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

bool is_symmetric(struct node_t *p, struct node_t *q) {
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return is_symmetric(p->left, q->right) && is_symmetric(p->right, q->left);
}

bool isSymmetric(node_t *root) { return is_symmetric(root->left, root->right); }
