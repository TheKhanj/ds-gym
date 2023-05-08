#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool is_all_same(char *s) {
	for (int i = 1; i < strlen(s); i++) {
		if (s[i] != s[i - 1]) {
			return false;
		}
	}

	return true;
}

int32_t main() {
	int32_t t;
	scanf("%d", &t);

	while (t--) {
		char s[100];
		scanf("%s", s);

		if (is_all_same(s)) {
			printf("-1\n");
			continue;
		}

		printf("%lu\n", strlen(s) - 1);
	}
}
