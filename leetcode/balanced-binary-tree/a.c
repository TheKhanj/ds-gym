#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define ABS(a) ((a) < 0 ? -(a) : (a))

typedef struct node_t {
	int val;
	struct node_t *left;
	struct node_t *right;
} node_t;

typedef struct check_t {
	bool is_balanced;
	int depth;
} check_t;

check_t check(node_t *node) {
	if (!node)
		return (check_t){
				.is_balanced = true,
				.depth = 0,
		};

	check_t l = check(node->left);
	check_t r = check(node->right);

	check_t ret = {
			.is_balanced =
					l.is_balanced && r.is_balanced && ABS(l.depth - r.depth) <= 1,
			.depth = MAX(l.depth, r.depth) + 1,
	};

	return ret;
}

bool isBalanced(struct node_t *root) { return check(root).is_balanced; }

void test() {
	int v[] = {1, 2, 2, 3, 3, -1, -1, 4, 4};
	int n = sizeof(v) / sizeof(v[0]);
	node_t nodes[n];
	for (int i = 0; i < n; i++) {
		node_t *node = nodes + i;

		int ptr = 2 * i + 1;
		node->left = (ptr < n && v[ptr] != -1 ? nodes + ptr : NULL);

		ptr++;
		node->right = (ptr < n && v[ptr] != -1 ? nodes + ptr : NULL);

		node->val = v[i];
	}

	printf("%d\n", isBalanced(nodes));
}

int main() { test(); }
