#include <stdio.h>
#include <stdlib.h>

int first_diff(int *arr, int *sorted, int n) {
	for (int i = 0; i < n; i++)
		if (arr[i] != sorted[i])
			return i;

	return n;
}

int last_diff(int *arr, int *sorted, int n) {
	for (int i = n - 1; i >= 0; i--)
		if (arr[i] != sorted[i])
			return i;

	return -1;
}

int cmp(const void *a, const void *b) {
	int x = *(int *)a;
	int y = *(int *)b;

	return x - y;
}

int are_the_same(int *arr, int *sorted, int n) {
	for (int i = 0; i < n; i++)
		if (arr[i] != sorted[i])
			return 0;
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n], sorted[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sorted[i] = arr[i];
	}

	qsort(sorted, n, sizeof(sorted[0]), cmp);

	if (are_the_same(arr, sorted, n)) {
		printf("yes\n%d %d\n", 1, 1);
		return 0;
	}

	int first = first_diff(arr, sorted, n);
	int last = last_diff(arr, sorted, n);

	for (int l = first, r = last; l < r; l++, r--) {
		arr[l] ^= arr[r];
		arr[r] ^= arr[l];
		arr[l] ^= arr[r];
	}

	if (are_the_same(arr, sorted, n))
		printf("yes\n%d %d\n", first + 1, last + 1);
	else
		printf("no\n");
}
