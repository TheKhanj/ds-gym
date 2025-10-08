#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char s[n + 1];
		scanf("%s", s);

		int cnt = 0;
		for (int i = 0, j = n - 1; i < j && s[i] != s[j]; i++, j--, cnt++) {
		}

		printf("%d\n", n - 2 * cnt);
	}
}
