#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int32_t main() {
	int32_t n;

	scanf("%d", &n);

	bool is_first = true;
	char curr[3], prev[3];
	int32_t ans = 1;

	while (n--) {
		scanf("%s", curr);
		if (is_first) {
			is_first = false;
		} else if (!!strcmp(curr, prev)) {
			ans++;
		}

		strcpy(prev, curr);
	}

	printf("%d", ans);
}
