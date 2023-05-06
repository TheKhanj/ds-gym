#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	char s1[101], s2[101];

	scanf("%s", s1);
	scanf("%s", s2);

	bool equal = true;

	const int32_t size = strlen(s1);
	for (int32_t i = 0, j = size - 1; i < size; i++, j--) {
		if (s1[i] != s2[j]) {
			equal = false;
		}
	}

	printf("%s", equal == true ? "YES" : "NO");
}
