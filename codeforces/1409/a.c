#include <stdio.h>

#define ABS(x) ((x) > 0 ? (x) : -(x))

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int diff = ABS(a - b);
		int ans = diff / 10;
		if (diff % 10) {
			ans++;
		}

		printf("%d\n", ans);
	}
}
