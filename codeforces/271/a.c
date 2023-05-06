#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool is_distinct(int32_t year) {
	bool vis[10];
	for (int32_t i = 0; i < 10; i++) {
		vis[i] = false;
	}

	while (year) {
		const int32_t mod = year % 10;
		if (vis[mod] == true) {
			return false;
		}

		vis[mod] = true;
		year /= 10;
	}

	return true;
}

int32_t main() {
	int32_t year;
	scanf("%d", &year);

	while (++year) {
		if (is_distinct(year)) {
			printf("%d", year);
			break;
		}
	}
}
