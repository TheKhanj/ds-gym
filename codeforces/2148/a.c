#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x, n;
		scanf("%d %d", &x, &n);
		printf("%d\n", n % 2 == 0 ? 0 : x);
	}
}
