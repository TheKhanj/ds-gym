#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool solve(char *s, int32_t n) {
	int32_t not_unique_count = 0;
	for (int32_t i = 0; i < n / 2;) {
		char c = s[i];
		while (i < n / 2 && s[i] == c) {
			i++;
		}
		not_unique_count++;
	}

	return not_unique_count > 1;
}

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	while (n--) {
		char s[51];
		scanf("%s", s);
		printf(solve(s, strlen(s)) ? "YES\n" : "NO\n");
	}
}
