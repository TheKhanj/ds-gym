#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d %d\n", MIN(a, b), (MAX(a, b) - MIN(a, b)) / 2);
}
