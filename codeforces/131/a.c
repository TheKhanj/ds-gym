#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool is_range_upper(char *s, int32_t l, int32_t r) {
	while (l < r) {
		if (islower(s[l])) {
			return false;
		}
		l++;
	}

	return true;
}

bool is_accidental_caps_lock(char *s, int32_t n) {
	return is_range_upper(s, 1, n);
}

void fix_accidental_caps_lock(char *s, int32_t n) {
	s[0] = isupper(s[0]) ? tolower(s[0]) : toupper(s[0]);

	while (--n > 0) {
		s[n] = tolower(s[n]);
	}
}

int32_t main() {
	char s[101];
	scanf("%s", s);

	int32_t n = strlen(s);

	if (!is_accidental_caps_lock(s, n)) {
		printf("%s", s);
		return 0;
	}

	fix_accidental_caps_lock(s, n);
	printf("%s", s);
}
