#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	char s[10];
	int32_t k;

	scanf("%s %d", s, &k);
	int32_t len = strlen(s);

	for (int32_t i = len - 1; i >= 0; i--) {
		int32_t val = s[i] - '0';
		if (k > val) {
			k -= val + 1;
			s[i] = '\0';
		} else {
			s[i] = val - k + '0';
			break;
		}
	}

	printf("%s", s);
}
