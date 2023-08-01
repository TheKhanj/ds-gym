#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int min = MIN(n, m);

	printf("%s\n", min % 2 == 0 ? "Malvika" : "Akshat");
}
