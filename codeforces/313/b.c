#include <stdio.h>
#include <string.h>

const int MAX_N = 1e5;

int main() {
	char s[MAX_N + 1];
	scanf("%s", s);
	int n = strlen(s);

	int dp[n - 1];
	for (int i = 0; i < n - 1; i++) {
		int eq = s[i] == s[i + 1];
		dp[i] = i == 0 ? eq : eq + dp[i - 1];
	}

	int q;
	scanf("%d", &q);

	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		printf("%d\n", dp[r - 1] - (l == 0 ? 0 : dp[l - 1]));
	}
}
