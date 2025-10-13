#include <stdio.h>

int is_bw_char(char c) { return c == 'B' || c == 'W' || c == 'G'; }

int is_bw_matrix(int n, int m) {
	char mat[n][m];
	for (int i = 0; i < n; i++) {
		char c[m + 1];
		for (int j = 0; j < m; j++) {
			scanf("%s", c);
			mat[i][j] = c[0];
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!is_bw_char(mat[i][j]))
				return 0;

	return 1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%s\n", is_bw_matrix(n, m) ? "#Black&White" : "#Color");
}
