#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool is_all_true(bool *arr, size_t size) {
	for (int32_t i = 0; i < size; i++) {
		if (arr[i] != true) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	int32_t n;

	scanf("%d", &n);

	bool vis[n];
	memset(vis, false, n);

	int32_t p, q;

	scanf("%d", &p);
	for (int32_t i = 0; i < p; i++) {
		int32_t x;
		scanf("%d", &x);

		vis[--x] = true;
	}

	scanf("%d", &q);
	for (int32_t i = 0; i < q; i++) {
		int32_t x;
		scanf("%d", &x);

		vis[--x] = true;
	}

	printf("%s",
		   is_all_true(vis, n) ? "I become the guy." : "Oh, my keyboard!");
}
