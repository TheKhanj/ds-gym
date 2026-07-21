#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	char c = s[0];
	int ans = 0;
	for (int i = 0; i < n;) {
		int sz = 0;
		while (i < n && s[i] == c)
			i++, sz++;

		if (i < n)
			c = s[i];

		ans = MAX(ans, sz);
	}
	printf("%d\n", ans + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
