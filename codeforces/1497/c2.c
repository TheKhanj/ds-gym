#include <stdio.h>

void solve_3(int n) {
	int k = 3;

	if (n % 2 == 1) {
		printf("%d ", 1);
		for (int i = 0; i < k - 1; i++)
			printf("%d ", (n - 1) / 2);
		printf("\n");
		return;
	}
	if (n % 4 != 0) {
		printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
		return;
	}
	printf("%d %d %d\n", n / 4, n / 4, n / 2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < k - 3; i++)
			printf("%d ", 1);
		solve_3(n - k + 3);
	}
}
