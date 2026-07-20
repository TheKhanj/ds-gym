#include <stdio.h>

void solve() {
	int x, k;
	scanf("%d %d", &x, &k);
	if (x % k != 0) {
		printf("1\n%d\n", x);
		return;
	}

	printf("2\n%d %d\n", x - 1, 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
