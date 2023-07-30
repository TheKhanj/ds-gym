#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			if (i % 2 == 0) {
				c = '#';
			} else {
				c = '.';
				if ((i % 4 == 1 && j == m - 1) || (i % 4 == 3 && j == 0)) {
					c = '#';
				}
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
