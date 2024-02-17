#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void test() {
	int n;
	scanf("%d", &n);
	n *= 2;
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(arr[0]), cmp);
	long long ans = 0;
	// printf("debug: ");
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");
	for (int i = n - 1; i >= 1; i -= 2)
		ans += arr[i - 1];
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
