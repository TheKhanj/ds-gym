#include <stdio.h>

int test_case() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k <= (4 * n - 4)) {

		return (k + 1) / 2;
	}
	return (4 * n - 4) / 2 + (k - (4 * n - 4));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int ans = test_case();
		printf("%d\n", ans);
	}
}
