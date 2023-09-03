#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a;
		scanf("%d", &a);
		int count = 0;
		for (int i = 0; i < 3; i++) {
			int x;
			scanf("%d", &x);
			if (x > a) {
				count++;
			}
		}

		printf("%d\n", count);
	}
}
