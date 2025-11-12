#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		int two = (b >= 2 * a) ? (2 * a) : b;
		printf("%d\n", (n / 2) * two + (n % 2) * a);
	}
}
