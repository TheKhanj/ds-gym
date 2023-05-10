#define __USE_MINGW_ANSI_STDIO 0

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static bool is_wub(char *s, int32_t n, int32_t i) {
	if (i > n - 3)
		return false;

	char sub_str[4];
	memcpy(sub_str, s + i, 3);
	return !strcmp(sub_str, "WUB");
}

int32_t main() {
	char s[201];

	scanf("%s", s);

	int32_t i = 0, n = strlen(s);

	while (is_wub(s, n, i)) {
		i += 3;
	}

	while (i < n) {
		printf("%c", s[i++]);

		bool first_loop = true;
		while (is_wub(s, n, i)) {
			if (first_loop) {
				printf(" ");
				first_loop = false;
			}

			i += 3;
		}
	}
}
