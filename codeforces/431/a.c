#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return *(char *)a > *(char *)b; }

void debug_arr(uint64_t *arr, int n) {
	printf("debug: ");
	for (int i = 0; i < n; i++) {
		printf("%" PRIu64 " ", arr[i]);
	}
	printf("\n");
}

void fill_count(char *s, int n, uint64_t *count) {
	for (int i = 0; i < 4; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n;) {
		char x = s[i];
		int y = s[i] - '1';
		while (i < n && s[i] == x) {
			count[y]++;
			i++;
		}
	}
}

int main() {
	uint64_t a[4];
	for (int i = 0; i < 4; i++) {
		scanf("%" SCNu64, a + i);
	}

	char s[100 * 1000 + 1];
	scanf("%s", s);

	int n = strlen(s);
	qsort(s, n, sizeof(s[0]), cmp);

	uint64_t count[4];
	fill_count(s, n, count);

	uint64_t ans = 0;
	// debug_arr(count, 4);
	// debug_arr(a, 4);
	for (int i = 0; i < 4; i++) {
		ans += count[i] * a[i];
	}

	printf("%" PRIu64 "\n", ans);
}
