#include <stdio.h>
#include <stdlib.h>

int is_possible(int *arr, int n) {
	for (int i = 1; i + 1 < n; i += 2)
		if (arr[i] != arr[i + 1])
			return 0;
	return 1;
}

int cmp(const void *a, const void *b) {
	int x = *(int *)a;
	int y = *(int *)b;

	return x - y;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		qsort(arr, n, sizeof(arr[0]), cmp);

		printf("%s\n", is_possible(arr, n) ? "YES" : "NO");
	}
}
