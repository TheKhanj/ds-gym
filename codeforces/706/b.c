#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int binary_search(int *arr, int l, int r, int money) {
	int mid = (l + r) / 2;
	if (l == r - 1) {
		return l;
	}

	if (arr[mid] <= money) {
		return binary_search(arr, mid, r, money);
	}

	return binary_search(arr, l, mid, money);
}

int main() {
	int n;
	scanf("%d", &n);
	int x[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
	}
	qsort(x, n, sizeof(x[0]), cmp);

	int q;
	scanf("%d", &q);
	while (q--) {
		int money;
		scanf("%d", &money);
		if (money < x[0]) {
			printf("0\n");
			continue;
		}
		printf("%d\n", 1 + binary_search(x, 0, n, money));
	}
}
