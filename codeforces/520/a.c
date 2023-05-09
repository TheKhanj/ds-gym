#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t cmp(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	char s[n + 1];
	scanf("%s", s);
	for (int32_t i = 0; i < n; i++) {
		s[i] = tolower(s[i]);
	}

	qsort(s, n, sizeof(char), cmp);

	char curr = 'a';
	for (int i = 0; i < n; i++) {
		if (s[i] == curr) {
			curr++;
		}
	}

	printf("%s", curr == ('z' + 1) ? "YES" : "NO");
}
