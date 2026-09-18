#include <stdio.h>

void solve() {
	int h, m;
	scanf("%d:%d", &h, &m);
	printf("%02d:%02d %s\n", (h + 11) % 12 + 1, m, h < 12 ? "AM" : "PM");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
