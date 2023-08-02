#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n, k, l, c, d, p, nl, np;
	scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

	int arr[] = {(c * d) / n, ((k * l) / nl) / n, (p / np) / n};

	qsort(arr, 3, sizeof(arr[0]), cmp);

	printf("%d\n", arr[0]);
}
