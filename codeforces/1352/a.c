#include <stdio.h>

void solve(int n) {
	int ten_power = 1;
	int ans[5];
	int sz = 0;
	while (n) {
		if (n % 10 != 0) {
			ans[sz++] = ten_power * (n % 10);
		}
		ten_power *= 10;
		n /= 10;
	}

	printf("%d\n", sz);
	while (sz--) {
		printf("%d ", ans[sz]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		solve(n);
	}
}
