#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int n, m, a, b;

	scanf("%d %d %d %d", &n, &m, &a, &b);

	if (a * m <= b) {
		printf("%d\n", a * n);
		return 0;
	}

	int min = MIN(a * (n % m), (n % m == 0 ? 0 : 1) * b);
	printf("%d\n", (n / m) * b + min);
}
