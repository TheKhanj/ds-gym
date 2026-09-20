#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int x = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		x ^= a;
	}

	if (x == 0) {
		printf("0\n");
		return;
	}
	if (n % 2 == 0) {
		printf("-1\n");
		return;
	}
	printf("%d\n", x);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
