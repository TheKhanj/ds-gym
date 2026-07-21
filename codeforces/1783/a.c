#include <stdio.h>
#include <stdlib.h>

int rev_cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

void swap(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(arr[0]), rev_cmp);

	if (arr[0] == arr[n - 1]) {
		printf("NO\n");
		return;
	}

	if (arr[0] == arr[1]) {
		int i = 1;
		while (i < n && arr[i] == arr[0])
			i++;
		swap(arr + i, arr + 1);
	}

	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
