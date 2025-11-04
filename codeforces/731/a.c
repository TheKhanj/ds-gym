#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	char s[101];
	scanf("%s", s);
	size_t len = strlen(s);

	char curr = 'a';
	int ans = 0;
	for (size_t i = 0; i < len; i++) {
		char c = s[i];
		ans += MIN((c - curr + 26) % 26, (curr - c + 26) % 26);
		curr = s[i];
	}
	printf("%d\n", ans);
}
