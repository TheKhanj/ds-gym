#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int ans = 0;
	int coins[] = {100, 20, 10, 5, 1};
	int coins_count = sizeof(coins) / sizeof(coins[0]);
	for (int i = 0; i < coins_count; i++) {
		ans += n / coins[i];
		n = n % coins[i];
	}

	printf("%d", ans);
}
