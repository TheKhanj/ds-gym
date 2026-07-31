#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

const int lg = 30;

long long get_min(long long *minarr, int l, int r, int i) {
	long long (*min)[lg] = (long long (*)[lg])minarr;
	int len = r - l + 1;

	long long ret = INTMAX_MAX;
	for (int jump = 0; jump < lg; jump++) {
		if ((len & (1 << jump)) == 0)
			continue;
		ret = MIN(ret, min[i][jump]);
		i -= (1 << jump);
	}
	return ret;
}

void update_min(long long *minarr, int i, long long *dp) {
	long long (*min)[lg] = (long long (*)[lg])minarr;
	for (int jump = 0; jump < lg; jump++) {
		if (jump == 0)
			min[i][jump] = dp[i];
		else {
			int bef = i - (1 << (jump - 1));
			if (bef < 0)
				min[i][jump] = min[i][jump - 1];
			else
				min[i][jump] = MIN(min[bef][jump - 1], min[i][jump - 1]);
		}
	}
}

long long calculate_row(int *arr, int m, int d) {
	long long dp[m], min[m][lg];
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			dp[i] = 1;
		} else {

			int l = MAX(0, i - d - 1);
			int r = i - 1;
			dp[i] = arr[i] + 1 + get_min((long long *)min, l, r, i - 1);
		}
		update_min((long long *)min, i, dp);
		// printf("%d ", dp[i]);
	}
	// printf("\n");

	return dp[m - 1];
}

void solve() {
	int n, m, k, d;
	scanf("%d %d %d %d", &n, &m, &k, &d);
	int arr[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	long long row[n];
	for (int i = 0; i < n; i++)
		row[i] = calculate_row(arr[i], m, d);

	long long ans, sum = 0;
	for (int i = 0; i < k; i++)
		sum += row[i];
	ans = sum;
	for (int i = k; i < n; i++) {
		sum -= row[i - k];
		sum += row[i];
		ans = MIN(ans, sum);
	}

	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
