#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *bs_shift(int *l, int *r, int *last) {
	if (l == r - 1) {
		if (r == last)
			return NULL;
		return l;
	}

	int *mid = (r - l) / 2 + l;

	if (*mid > *l)
		return bs_shift(mid, r, last);

	return bs_shift(l, mid, last);
}

int get_shift(int *arr, int n) {
	int *ptr = bs_shift(arr, arr + n, arr + n);
	if (ptr == NULL)
		return 0;

	int l = ptr - arr + 1;

	return n - l;
}

int *binary_search(int *arr, int l, int r, int target, int shift, int n) {
	if (l == r - 1) {
		if (arr[(l - shift + n) % n] == target)
			return arr + l;
		return NULL;
	}

	int mid = (r - l) / 2 + l;
	if (target >= arr[(mid - shift + n) % n])
		return binary_search(arr, mid, r, target, shift, n);
	return binary_search(arr, l, mid, target, shift, n);
}

int search(int *arr, int n, int target) {
	int shift = get_shift(arr, n);

	int *ptr = binary_search(arr, 0, n, target, shift, n);

	if (ptr == NULL)
		return -1;

	int index = ptr - arr;

	return (index + n - shift) % n;
}

void test() {
	int arr1[] = {4, 5, 6, 7, 0, 1, 2};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	assert(search(arr1, n1, 0) == 4);

	int arr2[] = {4, 5, 6, 7, 0, 1, 2};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(search(arr2, n2, 3) == -1);

	int arr3[] = {1};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(search(arr3, n3, 0) == -1);
}

int main() { test(); }
