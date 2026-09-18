#include <stdio.h>

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	char s[n + 1];
	scanf("%s", s);

	int cnt[26];
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'A']++;
	int ans = 0;
	for (int i = 'A' - 'A'; i <= 'G' - 'A'; i++)
		if (cnt[i] < m) {
			fprintf(stderr, "%c: %d\n", i + 'A', cnt[i]);
			ans += m - cnt[i];
		}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
