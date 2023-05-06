#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int32_t main() {
	int32_t a[4];

	for (int i = 0; i < 4; i++) {
		scanf("%d", a + i);
	}

	qsort(a, 4, sizeof(int32_t), cmp);

	int32_t not_unique = 0;
	for (int i = 0; i < 4;) {
		int32_t first = a[i++];
		while (a[i] == first) {
			not_unique++;
			i++;
		}
	}

	printf("%d", not_unique);
}
