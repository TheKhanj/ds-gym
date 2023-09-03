#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main() {
	int x;
	scanf("%d", &x);
	if (x >= 0) {
		printf("%d", x);
		return 0;
	}
	x = -x;

	printf("%d\n", -MIN(x / 10, (int)((int)(x / 100) * 10 + x % 10)));
}
