#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	for (int32_t i = 0; i < n; i++) {
		int32_t is_hard;
		scanf("%d", &is_hard);
		if (is_hard) {
			printf("hard");
			return 0;
		}
	}
	printf("easy");
}
