#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long calculate_row(const int *arr, int m, int d) {
	long long *dp = (long long *)malloc(m * sizeof(*dp));

	// Stores indices of dp[].
	// dp[deque[0]] is always the minimum in the current window.
	int *deque = (int *)malloc(m * sizeof(*deque));
	int head = 0;
	int tail = 0;

	dp[0] = 1;
	deque[tail++] = 0;

	for (int i = 1; i < m; i++) {
		int left = i - d - 1;

		// Remove indices that are outside the valid range.
		while (head < tail && deque[head] < left)
			head++;

		dp[i] = arr[i] + 1 + dp[deque[head]];

		// Maintain increasing dp values in the deque.
		while (head < tail && dp[deque[tail - 1]] >= dp[i])
			tail--;

		deque[tail++] = i;
	}

	long long result = dp[m - 1];

	free(dp);
	free(deque);

	return result;
}

void solve(void) {
	int n, m, k, d;
	scanf("%d %d %d %d", &n, &m, &k, &d);

	int (*arr)[m] = (int (*)[m])malloc(n * sizeof(*arr));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	long long *row = (long long *)malloc(n * sizeof(*row));

	for (int i = 0; i < n; i++)
		row[i] = calculate_row(arr[i], m, d);

	long long sum = 0;

	for (int i = 0; i < k; i++)
		sum += row[i];

	long long answer = sum;

	for (int i = k; i < n; i++) {
		sum -= row[i - k];
		sum += row[i];
		answer = MIN(answer, sum);
	}

	printf("%lld\n", answer);

	free(row);
	free(arr);
}

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--)
		solve();
}
