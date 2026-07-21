#include <assert.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int uniq(int count[26]) {
	int ret = 0;
	for (int i = 0; i < 26; i++)
		ret += count[i] == 0 ? 0 : 1;
	return ret;
}

void solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int count[2][n][26];
	for (int i = 0; i < n; i++) {
		char c = s[i];
		for (int j = 0; j < 26; j++)
			count[0][i][j] = i == 0 ? 0 : count[0][i - 1][j];

		count[0][i][c - 'a']++;
	}
	for (int i = n - 1; i >= 0; i--) {
		char c = s[i];
		for (int j = 0; j < 26; j++)
			count[1][i][j] = i == n - 1 ? 0 : count[1][i + 1][j];

		count[1][i][c - 'a']++;
	}

	int ans = 0;
	for (int i = 1; i < n; i++) {
		int x = uniq(count[0][i - 1]) + uniq(count[1][i]);
		ans = MAX(ans, x);
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
