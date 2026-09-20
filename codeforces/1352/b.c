#include <stdio.h>

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);

	if (n % 2 == 1 && k % 2 == 0) {
		printf("NO\n");
		return;
	}
	if (n % 2 == 1 || k % 2 == 0) {
		if (n < k) {
			printf("NO\n");
			return;
		}
		printf("YES\n");
		for (int i = 0; i < k - 1; i++)
			printf("1 ");
		printf("%d\n", n - k + 1);
		return;
	}
	if (n < 2 * k) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for (int i = 0; i < k - 1; i++)
		printf("2 ");
	printf("%d\n", n - 2 * k + 2);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
