#include <stdbool.h>
#include <stdio.h>

void answer(int n, int k, int x) {
	if (x != 1) {
		printf("YES\n");
		printf("%d\n", n);
		for (int i = 0; i < n; i++)
			printf("1 ");
		printf("\n");
		return;
	}

	// x==1
	if (k == 1 || (k == 2 && n % 2 == 1)) {
		printf("NO\n");
		return;
	}

	printf("YES\n");
	printf("%d\n", n / 2);
	printf("%d ", n % 2 == 0 ? 2 : 3);
	for (int i = 1; i < n / 2; i++)
		printf("%d ", 2);
	printf("\n");
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k, x;
		scanf("%d %d %d", &n, &k, &x);
		answer(n, k, x);
	}
}
