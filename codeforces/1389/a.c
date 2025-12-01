#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (2 * a <= b)
			printf("%d %d\n", a, 2 * a);
		else
			printf("-1 -1\n");
	}
}
