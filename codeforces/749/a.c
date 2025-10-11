#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n / 2);
	for (int i = 0; i < n / 2; i++) {
		printf("%d", n % 2 != 0 && i == n / 2 - 1 ? 3 : 2);
		if (i != n / 2 - 1)
			printf(" ");
	}
	printf("\n");
}
