#include <stdio.h>

int range_sum(int *arr, int l, int r) {
	int sum = 0;
	while (l < r) {
		sum += arr[l];
		l++;
	}
	return sum;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[n];

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int ans = 0; 
	int min = range_sum(arr, 0, k);
	int sum = min;

	for (int l = 1, r = k; r < n; r++, l++) {
		sum += arr[r];
		sum -= arr[l - 1];
		if (sum < min) {
			min = sum;
			ans = l;
		}
	}

	printf("%d\n", ans + 1);
}
