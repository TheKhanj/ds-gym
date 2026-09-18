#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 2; i <= n; i++)
		ans += n % i == 0 ? 1 : 0;
	printf("%d\n", ans);
}
