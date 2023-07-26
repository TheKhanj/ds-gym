#include <stdio.h>

int get_count(int x, int *arr, int n) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			ret++;
		}
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int h[n], g[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", h + i, g + i);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += get_count(g[i], h, n);
	}

	printf("%d\n", ans);
}
