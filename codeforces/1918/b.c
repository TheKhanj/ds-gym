#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void test_case() {
	int n;
	scanf("%d", &n);
	int a[n][2];
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i][j]);
	qsort(a, n, sizeof(a[0]), cmp);

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
