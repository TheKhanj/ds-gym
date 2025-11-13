#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n >= 4)
			printf("%d\n", n / 2 + (n % 2));
		else
			printf("%d\n", n >= 3 ? 2 : 1);
	}
}
