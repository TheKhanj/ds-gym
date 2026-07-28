#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	char s[n + 1];
	scanf("%s", s);

	int white[n];
	for (int i = 0; i < n; i++)
		white[i] = (s[i] == 'W' ? 1 : 0) + (i == 0 ? 0 : white[i - 1]);

	int ans = n;
	for (int l = -1, r = k - 1; r < n; l++, r++) {
		int whites = white[r] - (l == -1 ? 0 : white[l]);
		ans = MIN(ans, whites);
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
