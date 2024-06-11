#include <stdio.h>

void test() {
	int n, m;
	scanf("%d %d", &n, &m);
	char mat[n][m + 1];
	int midx, midy;
	for (int i = 0; i < n; ++i) {
		scanf("%s", mat[i]);
		char *s = mat[i];
		long long p = 0;
		int c = 0;
		for (int j = 0; j < m; j++)
			if (s[j] == '#') {
				p += j;
				c++;
				midy = p / c;
			}
	}

	for (int j = 0; j < m; ++j) {
		long long p = 0;
		int c = 0;
		for (int i = 0; i < n; i++)
			if (mat[i][j] == '#') {
				p += i;
				c++;
				midx = p / c;
			}
	}

	printf("%d %d\n", midx + 1, midy + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
