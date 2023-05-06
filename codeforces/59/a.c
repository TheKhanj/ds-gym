#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	char s[100];
	scanf("%s", s);
	int32_t len = strlen(s);

	int32_t upper = 0, lower = 0;

	for (int32_t i = 0; i < len; i++) {
		char c = s[i];
		if (isupper(c)) {
			upper++;
		} else {
			lower++;
		}
	}

	int (*convert)(int) = upper > lower ? toupper : tolower;

	for (int32_t i = 0; i < len; i++) {
		s[i] = convert(s[i]);
	}

	printf("%s", s);
}
