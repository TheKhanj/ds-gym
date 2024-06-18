#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <vector>

const int INF = 1e9 + 7;
int n, m;
int group_id = 0;
std::vector<std::vector<char>> s;
std::vector<std::vector<int>> vis;

typedef struct {
	int id;
	int size;
	int left, right, top, bottom;
} group_t;

std::vector<group_t> groups;

int index(int i, int j) { return i * m + j; }

void dfs(int i, int j, group_t *g) {
	if (i < 0 || j < 0 || i >= n || j >= m || s[i][j] == '.' || vis[i][j])
		return;
	vis[i][j] = 1;

	g->size++;

	g->left = std::min(j, g->left);
	g->right = std::max(j, g->right);
	g->top = std::min(i, g->top);
	g->bottom = std::max(i, g->bottom);

	dfs(i - 1, j, g);
	dfs(i + 1, j, g);
	dfs(i, j - 1, g);
	dfs(i, j + 1, g);
}

void group_init(group_t *g) {
	g->size = 0;
	g->left = INF;
	g->right = -INF;
	g->top = INF;
	g->bottom = -INF;
}

void debug(int *arr, int n, const char *s) {
	printf("%s ", s);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void test() {
	scanf("%d %d", &n, &m);
	groups.clear();
	s.assign(n, std::vector<char>(m, ' '));
	vis.assign(n, std::vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		char line[m];
		scanf("%s", line);
		for (int j = 0; j < m; j++)
			s[i][j] = line[j];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || s[i][j] == '.')
				continue;

			group_t g;
			group_init(&g);
			g.id = ++group_id;
			dfs(i, j, &g);
			groups.push_back(g);
		}

	int freeR[n], freeC[m];
	memset(freeR, 0, n * sizeof(*freeR));
	memset(freeC, 0, m * sizeof(*freeC));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			freeR[i] += (s[i][j] == '.');
			freeC[j] += (s[i][j] == '.');
		}

	int row[n + 4], col[m + 4], rowcol[n + 4][m + 4];
	memset(row, 0, (n + 4) * sizeof(*row));
	memset(col, 0, (m + 4) * sizeof(*col));
	memset(rowcol, 0, (m + 4) * (n + 4) * sizeof(**rowcol));

	for (auto group : groups) {
		row[group.top - 1 + 1] += group.size;
		row[group.bottom + 2 + 1] -= group.size;
		col[group.left - 1 + 1] += group.size;
		col[group.right + 2 + 1] -= group.size;

		rowcol[group.top - 1 + 1][group.left - 1 + 1] += group.size;
		rowcol[group.bottom + 2 + 1][group.left - 1 + 1] -= group.size;
		rowcol[group.top - 1 + 1][group.right + 2 + 1] -= group.size;
		rowcol[group.bottom + 2 + 1][group.right + 2 + 1] += group.size;
	}

	for (int i = 1; i < n + 3; i++)
		row[i] += row[i - 1];
	for (int j = 1; j < m + 3; j++)
		col[j] += col[j - 1];

	for (int i = 0; i < n + 3; i++)
		for (int j = 0; j < m + 3; j++) {
			if (i > 0)
				rowcol[i][j] += rowcol[i - 1][j];
			if (j > 0)
				rowcol[i][j] += rowcol[i][j - 1];
			if (i > 0 && j > 0)
				rowcol[i][j] -= rowcol[i - 1][j - 1];
		}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = freeR[i] + freeC[j] - (s[i][j] == '.');
			x += row[i + 1] + col[j + 1] - rowcol[i + 1][j + 1];
			ans = std::max(ans, x);
		}
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
