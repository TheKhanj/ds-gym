#include <stdio.h>

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	int ans = 0;
	for (int a = 1; a * a <= x && a <= n; a++) {
		if (x % a != 0)
			continue;
		int b = x / a;
		if (!(a <= n && b <= n))
			continue;
		// fprintf(stderr, "a: %d, b: %d\n", a, b);
		ans += 2;
		if (a == b)
			ans--;
	}
	printf("%d\n", ans);
}
