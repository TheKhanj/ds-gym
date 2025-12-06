#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		printf("-1\n");
		return 0;
	}

	for (int i = 1; i <= n; i += 2)
		printf("%d %d ", i + 1, i);
	printf("\n");
}
