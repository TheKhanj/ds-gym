#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void test_case() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof arr[0], cmp);
	printf("%d\n", arr[n-1] - arr[0]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
