#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a;
		scanf("%d", &a);
		int min = a % 10;
		while (a) {
			min = MIN(min, a % 10);
			a /= 10;
		}
		printf("%d\n", min);
	}
}
