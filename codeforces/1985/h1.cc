#include <cassert>
#include <cstring>
#include <set>
#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define WITH_RANGE_ADJ(n, m, i, j)                                             \
	((i) >= 0 && (i) < (n) && (j) >= 0 && (j) < (m)) ? &nodes[i][j]              \
																									 : (node_t *)NULL

typedef struct node_t {
	int group;
	int has;
	node_t *adj[4];
} node_t;

void dfs(node_t *node, int *g_size, int g_id) {
	node->group = g_id;
	g_size[g_id]++;
	for (int i = 0; i < 4; i++) {
		node_t *adj = node->adj[i];
		if (!adj)
			continue;
		if (!adj->has)
			continue;
		if (adj->group) {
			assert(adj->group == g_id);
			continue;
		}
		dfs(adj, g_size, g_id);
	}
}

void get_col(node_t *nodes, node_t *col, int n, int m, int j) {
	for (int i = 0; i < n; i++)
		col[i] = nodes[i * m + j];
}

int get_max_size(node_t *nodes, int n, int adj[2], int *g_size) {
	std::set<int> groups;
	int size = 0;
	for (int i = 0; i < n; i++) {
		node_t *node = &nodes[i];
		if (node->group != 0) {
			groups.insert(node->group);
			continue;
		}

		if (!node->has)
			size++;

		if (node->adj[adj[0]])
			groups.insert(node->adj[adj[0]]->group);
		if (node->adj[adj[1]])
			groups.insert(node->adj[adj[1]]->group);
	}

	for (auto g_id = groups.begin(); g_id != groups.end(); g_id++)
		size += g_size[*g_id];

	return size;
}

void test() {
	int n, m;
	scanf("%d %d", &n, &m);
	char s[n][m];
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);

	node_t nodes[n][m];
	memset(nodes, 0, n * m * sizeof(**nodes));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			node_t *node = &nodes[i][j];
			node->has = s[i][j] == '#' ? 1 : 0;
			node->adj[0] = WITH_RANGE_ADJ(n, m, i - 1, j);
			node->adj[1] = WITH_RANGE_ADJ(n, m, i, j + 1);
			node->adj[2] = WITH_RANGE_ADJ(n, m, i + 1, j);
			node->adj[3] = WITH_RANGE_ADJ(n, m, i, j - 1);
		}

	int g_count = 1;
	int g_size[n * m];
	memset(g_size, 0, n * m * sizeof(*g_size));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			node_t *node = &nodes[i][j];
			if (node->group)
				continue;
			if (node->has)
				dfs(node, g_size, g_count++);
		}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		node_t *row = nodes[i];

		int adj[] = {0, 2};
		int size = get_max_size(row, m, adj, g_size);
		ans = MAX(ans, size);
	}

	for (int j = 0; j < m; j++) {
		node_t col[n];
		get_col((node_t *)nodes, col, n, m, j);

		int adj[] = {1, 3};
		int size = get_max_size(col, n, adj, g_size);
		ans = MAX(ans, size);
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
