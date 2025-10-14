#include <stdio.h>

int is_other(char c) { return c == 'B' || c == 'G'; }

int identical(char a, char b) { return a == b || (is_other(a) && is_other(b)); }

int identical_rows(int n, char mat[2][n + 1]) {
	for (int i = 0; i < n; i++) {
		if (!identical(mat[0][i], mat[1][i]))
			return 0;
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char mat[2][n + 1];
		scanf("%s", mat[0]);
		scanf("%s", mat[1]);
		printf("%s\n", identical_rows(n, mat) ? "YES" : "NO");
	}
}
