#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (201)

int cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int main() {
	char a[MAX_N], b[MAX_N], c[MAX_N], concat[MAX_N];
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);

	size_t size_a = strlen(a);
	size_t size_b = strlen(b);
	size_t size_c = strlen(c);

	for (size_t i = 0; i < size_a; ++i) {
		concat[i] = a[i];
	}

	for (size_t i = size_a; i < size_a + size_b; ++i) {
		concat[i] = b[i - size_a];
	}

	concat[size_c] = 0;

	qsort(concat, size_a + size_b, sizeof(a[0]), cmp);
	qsort(c, size_c, sizeof(a[0]), cmp);

	printf("%s\n", (strcmp(c, concat) == 0) ? "YES" : "NO");
}
