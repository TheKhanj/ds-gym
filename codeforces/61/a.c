#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	char s[2][101], ans[101];
	scanf("%s", s[0]);
	scanf("%s", s[1]);

	const int32_t size = strlen(s[0]);

	for (int i = 0; i < size; i++) {
		ans[i] = s[0][i] == s[1][i] ? '0' : '1';
	}

	ans[size] = '\0';

	printf("%s", ans);
}
