#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int *left = arr, *right = arr + n - 1;

	int pos = 0;
	int sum[2] = {0, 0};

	while (left <= right) {
		if (*left > *right) {
			sum[pos] += *left;
			left++;
		} else {
			sum[pos] += *right;
			right--;
		}
		pos = !pos;
	}

	printf("%d %d\n", sum[0], sum[1]);
}
