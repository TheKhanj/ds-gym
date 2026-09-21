#include <stdio.h>

void solve() {
	int w, h, n;
	scanf("%d %d %d", &w, &h, &n);
	int c = 1;
	while (w % 2 == 0)
		w /= 2, c *= 2;
	while (h % 2 == 0)
		h /= 2, c *= 2;
	printf("%s\n", c >= n ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
