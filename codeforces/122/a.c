#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

static bool is_digit_lucky(int32_t x) { return x == 4 || x == 7; }

static bool is_lucky(int32_t x) {
	while (x) {
		const int32_t mod = x % 10;
		if (!is_digit_lucky(mod)) {
			return false;
		}
		x /= 10;
	}

	return true;
}

static bool is_almost_lucky(int32_t n) {
	for (int i = 1; i <= n; i++) {
		if (is_lucky(i) && n % i == 0) {
			return true;
		}
	}

	return false;
}

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	printf("%s", is_almost_lucky(n) ? "YES" : "NO");
}
