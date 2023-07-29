#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int x;
		if ((n + 1) % 2 == 0) {
			x = (n + 1) / 2;
		} else {
			x = (n + 2) / 2;
		}

		printf("%d\n", n - x);
	}
}
