#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long long get_dp(int *arr, int n, int index, int threshold, int t) {
	if (index + 1 < t) {
		return 0;
	}

	if (t == 0) {
		if (threshold < 0) {
			return 1;
		} else {
			return 0;
		}
	}

	// should not come here
	if (index == -1) {
		printf("%d %d\n", index, t);
		assert(true == false);
		return 0;
	}

	return get_dp(arr, n, index - 1, threshold - arr[index], t - 1) +
				 get_dp(arr, n, index - 1, threshold, t);
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	qsort(arr, n, sizeof(arr[0]), cmp);

	// >= arr[i]
	long long int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 0;

	for (int i = 0; i < n - 1; i++) {
		int threshold = arr[i + 1];
		dp[i] = get_dp(arr, n, i, threshold, k - 1);
	}

	long long ans = 0;
	for (int i = k - 1; i < n; i++) {
		ans += dp[i - 1];
	}

	printf("%lld\n", ans);
}
