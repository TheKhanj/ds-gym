#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n % 2 == 0 || (n - 4) % 3 == 0) {
		printf("%d %d\n", 4, n - 4);
		return 0;
	}

	if ((n - 6) % 3 == 0) {
		printf("%d %d\n", 6, n - 6);
		return 0;
	}

	printf("%d %d\n", 8, n - 8);
}
