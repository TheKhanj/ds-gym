#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LG_N (30)

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct tree_t tree_t;
typedef struct node_t node_t;

struct node_t {
	bool prepared;
	int index;
	void *parents[LG_N];
	int height;
};

struct tree_t {
	int size;
	node_t *nodes;
};

void tree_init(tree_t *t, int size) {
	t->size = size;
	t->nodes = malloc(sizeof(node_t) * size);
	for (node_t *node = t->nodes; node < t->nodes + t->size; ++node) {
		for (int i = 0; i < LG_N; ++i) {
			node->parents[i] = NULL;
		}
	}
}

void node_init(node_t *node, int index) {
	node->index = index;
	node->height = 0;
	node->prepared = false;
}

node_t *node_get_parent(node_t *node, int jump) {
	assert(jump <= node->height);

	node_t *ret = node;

	for (int j = LG_N - 1; j >= 0; j--) {
		if (jump & (1 << j)) {
			ret = ret->parents[j];
		}
	}

	return ret;
}

node_t *tree_get_lca(tree_t *t, node_t *node1, node_t *node2) {
	int h1 = node1->height;
	int h2 = node2->height;
	int max_height = MAX(h1, h2);
	int diff = ABS(h1 - h2);

	node_t *left = node1;
	node_t *right = node2;

	if (h1 > h2) {
		left = node2;
		right = node1;
	}

	right = node_get_parent(right, diff);

	if (left == right) {
		return left;
	}

	for (int j = LG_N - 1; j >= 0; j--) {
		if (left->parents[j] != right->parents[j]) {
			left = left->parents[j];
			right = right->parents[j];
		}
	}

	return left->parents[0];
}

void node_prepare(node_t *node) {
	node_t *parent = node->parents[0];

	if (parent == NULL) {
		node->height = 0;
	} else {
		node_prepare(parent);
		node->height = parent->height + 1;
	}

	for (int i = 1; i < LG_N; ++i) {
		node_t *first_parent = node->parents[i - 1];
		node_t *second_parent =
				(first_parent == NULL ? NULL : first_parent->parents[i - 1]);
		node->parents[i] = second_parent;
	}
}

void tree_prepare(tree_t *t) {
	for (node_t *node = t->nodes; node < t->nodes + t->size; ++node) {
		if (node->prepared) {
			continue;
		}
		node->prepared = true;
		node_prepare(node);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int children_count;
	int child;

	tree_t t;
	tree_init(&t, n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &children_count);
		node_t *node = t.nodes + i;

		node_init(node, i);

		while (children_count--) {
			scanf("%d", &child);
			t.nodes[child].parents[0] = node;
		}
	}

	tree_prepare(&t);

	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		node_t *node = tree_get_lca(&t, t.nodes + a, t.nodes + b);
		printf("%d\n", node->index);
	}
}
