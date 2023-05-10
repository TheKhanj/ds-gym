#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENGLISH_CHARACTERS_COUNT 26

static void skip_spaces(char *s, int32_t *i) {
	while (s[*i] == ' ') {
		(*i)++;
	}
}

int32_t main() {
	char s[1001];

	fgets(s, sizeof(s), stdin);
	int32_t n = strlen(s);

	bool vis[ENGLISH_CHARACTERS_COUNT];
	memset(vis, 0, ENGLISH_CHARACTERS_COUNT);

	for (int32_t i = 1; i < n - 1; i++) {
		skip_spaces(s, &i);

		char c = s[i];
		vis[c - 'a'] = true;

		skip_spaces(s, &i);

		char comma = s[i];
		if (comma == ',')
			i++;
	}

	int32_t visited_count = 0;
	for (int32_t i = 0; i < ENGLISH_CHARACTERS_COUNT; i++) {
		if (vis[i] == true)
			visited_count++;
	}

	printf("%d", visited_count);
}
