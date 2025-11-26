#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(arr[0]), cmp);
	long long l = 0, r = n - 1;
	while (l < n && arr[l] == arr[0])
		l++;
	while (r >= 0 && arr[r] == arr[n - 1])
		r--;
	r = n - 1 - r;
	long long ans = r * l;
	if (arr[n - 1] == arr[0])
		ans = (l - 1) * l / 2;
	printf("%d %lld\n", arr[n - 1] - arr[0], ans);
}
