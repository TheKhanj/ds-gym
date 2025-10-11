#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool match(int boy, int girl) { return ABS(boy - girl) <= 1; }

int main() {
	int n;
	scanf("%d", &n);
	int boys[n];
	for (int i = 0; i < n; i++)
		scanf("%d", boys + i);
	int m;
	scanf("%d", &m);
	int girls[m];
	for (int i = 0; i < m; i++)
		scanf("%d", girls + i);

	qsort(boys, n, sizeof(boys[0]), cmp);
	qsort(girls, m, sizeof(girls[0]), cmp);

	int dp[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int boy = boys[i], girl = girls[j];
			if (!match(boy, girl)) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 1;

			for (int x = 0; x < i; x++)
				for (int y = 0; y < j; y++)
					dp[i][j] = MAX(dp[i][j], dp[x][y] + 1);
		}
	}
	int ans = 0;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			ans = MAX(ans, dp[x][y]);
	printf("%d\n", ans);
}
