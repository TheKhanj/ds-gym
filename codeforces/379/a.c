#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int ans = 0;
	while (a >= b) {
		ans += a - (a % b);
		a = (a % b) + (a / b);
	}
	ans += a % b;
	printf("%d\n", ans);
}
