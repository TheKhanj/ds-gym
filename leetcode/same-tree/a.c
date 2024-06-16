#include <stdbool.h>

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

bool isSameTree(struct node_t *p, struct node_t *q) {
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
