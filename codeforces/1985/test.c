#include <stdio.h>

int d(int a) {
	int c = 0;
	while (a) {
		c += a % 10;
		a /= 10;
	}
	return c;
}

int main() {
	printf("# \t");
	for (int i = 0; i <= 20; i++)
		printf("%d ", i);
	printf("\n");
	for (int i = 0; i <= 10; i++) {
		printf("%d \t", i);
		for (int j = 0; j <= 10; j++) {
			printf("%d ", d(i * j) == 10* i * d(j));
		}
		printf("\n");
	}
}
