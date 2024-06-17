#define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

int maxDepth(node_t *root) {
	if (!root)
		return 0;

	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return MAX(l, r) + 1;
}
