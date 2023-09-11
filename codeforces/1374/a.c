#include <stdio.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x, y;
		scanf("%d %d %d", &x, &y, &n);
		int ans = ((int)(n / x)) * x + y;
		while (ans > n) {
			ans -= x;
		}

		printf("%d\n", ans);
	}
}
