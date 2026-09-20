#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	int m, a, b, c;
	scanf("%d %d %d %d", &m, &a, &b, &c);
	int r1 = MIN(a, m);
	int r2 = MIN(b, m);

	int c1 = MIN(m - r1, c);
	c -= c1;
	int c2 = MIN(m - r2, c);
	c -= c2;

	printf("%d\n", r1 + r2 + c1 + c2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
