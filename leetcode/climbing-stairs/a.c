#include <string.h>

int climbStairs(int n) {
	if (n == 1)
		return 1;
	int dp[n];
	memset(dp, 0, sizeof(int) * n);
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i < n; i++) {
		if (i >= 2)
			dp[i] += dp[i - 2];
		if (i >= 1)
			dp[i] += dp[i - 1];
	}
	return dp[n - 1];
}
