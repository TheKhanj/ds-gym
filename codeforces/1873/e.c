#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int check(int *arr, int n, int water, int h) {
	long long block = 0;
	for (int i = 0; i < n; i++)
		block += MIN(h, arr[i]);
	return ((long long)h * (long long)n - block) <= water;
}

int binary_search(int *arr, int n, int water, int l, int r) {
	int mid = l + (r - l) / 2;
	if (l == r - 1)
		return l;
	if (check(arr, n, water, mid))
		return binary_search(arr, n, water, mid, r);
	return binary_search(arr, n, water, l, mid);
}

void solve() {
	int n, water;
	scanf("%d %d", &n, &water);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int h = binary_search(arr, n, water, 0, 2e9 + 1);
	printf("%d\n", h);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
