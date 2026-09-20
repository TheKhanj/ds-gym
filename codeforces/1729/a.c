#include <stdio.h>

#define ABS(a) ((a) < 0 ? -(a) : (a))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int x = a - 1;
		int y = ABS(b - c) + c - 1;
		fprintf(stderr, "x: %d, y: %d\n", x, y);
		printf("%d\n", x < y ? 1 : y < x ? 2 : 3);
	}
}
