#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int minPairSum(int *arr, int n) {
	qsort(arr, n, sizeof(arr[0]), cmp);
	int max = 0;
	for (int i = 0; i * 2 < n; i++)
		max = MAX(max, arr[i] + arr[n - i - 1]);
	return max;
}

void test() {
	int arr[] = {3, 5, 4, 2, 4, 6};
	printf("%d\n", minPairSum(arr, sizeof(arr) / sizeof(arr[0])));
}

int main() { test(); }
