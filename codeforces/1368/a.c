#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

void swap(int *a, int *b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void solve() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	int ans = 0;
	while (MAX(a, b) <= n) {
		if (a > b)
			swap(&a, &b);
		fprintf(stderr, "debug: %d %d\n", a, b);
		a += b, ans++;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
