#include <stdio.h>

#define ABS(a) ((a) < 0 ? -(a) : (a))

void solve() {
	int n = 4;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", x + i, y + i);
	int w, h;
	for (int i = 1; i < n; i++) {
		if (x[i] == x[0])
			w = y[i] - y[0];
		if (y[i] == y[0])
			h = x[i] - x[0];
	}
	printf("%d\n", ABS(h * w));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
