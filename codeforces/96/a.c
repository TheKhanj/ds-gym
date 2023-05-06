#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX(x, y) x > y ? x : y

int32_t main() {
	char s[100];

	scanf("%s", s);
	const int32_t len = strlen(s);

	int32_t ans = 0;
	for (int32_t i = 0; i < len;) {
		char first = s[i];

		int32_t size = 0;
		while (s[i] == first) {
			i++;
			size++;
		}

		ans = MAX(ans, size);
	}

	printf("%s", ans >= 7 ? "YES" : "NO");
}
