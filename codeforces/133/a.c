#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool does_print_anything(char *s) {
	const size_t size = strlen(s);

	for (int i = 0; i < size; i++) {
		char c = s[i];
		if (c == 'Q') {
			return true;
		}
		if (c == 'H' || c == '9') {
			return true;
		}
	}

	return false;
}

int32_t main() {
	char s[101];
	scanf("%s", s);

	printf("%s", does_print_anything(s) ? "YES" : "NO");
}
