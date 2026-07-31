#include <stdio.h>

void print_possibility(int n, int m, int *possibility) {
	int (*p)[m + 1] = (int (*)[m + 1]) possibility;
	printf("possibility:\n");
	for (int j = 0; j < m + 1; j++) {
		for (int i = 0; i < n; i++)
			printf("%d ", p[i][j]);
		printf("\n");
	}
}

void solve() {
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	int move[m], move_dir[m];
	for (int i = 0; i < m; i++) {
		char c;
		scanf("%d %c", move + i, &c);
		if (c == '0')
			move_dir[i] = 0;
		if (c == '1')
			move_dir[i] = 1;
		if (c == '?')
			move_dir[i] = 2;
	}

	int possibility[n][m + 1];
	for (int i = 0; i < n; i++)
		possibility[i][0] = 0;
	possibility[x - 1][0] = 1;

	for (int j = 1; j < m + 1; j++) {
		for (int i = 0; i < n; i++) {
			// printf("movej: %d, i: %d, j: %d\n", move[j], i, j);
			int l = possibility[(n + i - move[j - 1]) % n][j - 1];
			int r = possibility[(i + move[j - 1]) % n][j - 1];
			int here;
			if (move_dir[j - 1] == 0)
				here = l;
			if (move_dir[j - 1] == 1)
				here = r;
			if (move_dir[j - 1] == 2)
				here = r || l;

			possibility[i][j] = here;
		}
	}

	int len = 0;
	for (int i = 0; i < n; i++)
		if (possibility[i][m])
			len++;
	printf("%d\n", len);
	if (len == 0)
		return;

	for (int i = 0; i < n; i++)
		if (possibility[i][m])
			printf("%d ", i + 1);
	printf("\n");

	// print_possibility(n, m, (int *)possibility);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
