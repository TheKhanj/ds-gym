#include <stdlib.h>

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

node_t *sortedArrayToBST(int *arr, int n) {
	if (n <= 0)
		return NULL;
	node_t *ret = calloc(1, sizeof(node_t));

	int mid = n / 2;
	ret->val = arr[mid];
	ret->left = sortedArrayToBST(arr, mid);
	ret->right = sortedArrayToBST(arr + mid + 1, n - mid - 1);

	return ret;
}
