#include <stdint.h>
#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	if (n % 4 != 0) {
		printf("NO\n");
		return;
	}

	printf("YES\n");

	for (int i = 0; i < n / 2; ++i) {
		printf("%d ", 2 * i + 2);
	}

	for (int i = 0; i < (n / 2) - 1; ++i) {
		printf("%d ", 2 * i + 1);
	}
	printf("%d\n", n + (n / 2) - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
