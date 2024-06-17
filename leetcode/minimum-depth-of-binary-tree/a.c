#define MIN(a, b) ((a) < (b) ? (a) : (b))

const int INF = 1e9;

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

int minDepth(node_t *root) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;

	int l = root->left ? minDepth(root->left) : INF;
	int r = root->right ? minDepth(root->right) : INF;

	return MIN(l, r) + 1;
}
