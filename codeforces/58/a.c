#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static const char HELLO[] = "hello";

static bool has_subhello(char *s, int32_t size, int32_t pos) {
	for (int i = pos, j = 0; i < size; i++) {
		if (s[i] == HELLO[j]) {
			j++;
		}

		if (j == strlen(HELLO)) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	char s[101];
	scanf("%s", s);

	bool has_hello = false;

	const int32_t size = strlen(s);
	for (int32_t i = 0; i < size; i++) {
		if (has_subhello(s, size, i)) {
			has_hello = true;
			break;
		}
	}

	printf("%s", has_hello ? "YES" : "NO");
}
