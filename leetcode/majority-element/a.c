#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int majorityElement(int *arr, int n) {
	qsort(arr, n, sizeof(arr[0]), cmp);
	for (int i = 0; i < n;) {
		int x = arr[i];
		int cnt = 0;
		while (i < n && arr[i] == x)
			cnt++, ++i;
		if (cnt > n / 2)
			return x;
	}
	return -1;
}
