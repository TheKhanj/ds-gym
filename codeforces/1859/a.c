#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int mod[2][n], mod_len[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		mod[arr[i] % 2][mod_len[arr[i] % 2]++] = arr[i];
	}
	qsort(arr, n, sizeof(arr[0]), cmp);

	if (arr[0] == arr[n - 1]) {
		printf("-1\n");
		return;
	}

	if (mod_len[1] == n || mod_len[0] == n) {
		int x = n - 1;
		while (x >= 0 && arr[x] == arr[n - 1])
			x--;
		x++;

		printf("%d %d\n", x, n - x);
		for (int i = 0; i < x; i++)
			printf("%d ", arr[i]);
		printf("\n");
		for (int i = x; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	printf("%d %d\n", mod_len[1], mod_len[0]);
	for (int i = 0; i < mod_len[1]; i++)
		printf("%d ", mod[1][i]);
	printf("\n");
	for (int i = 0; i < mod_len[0]; i++)
		printf("%d ", mod[0][i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
