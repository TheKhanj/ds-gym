#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_power_of_two(int64_t x) {
	while (x % 2 == 0)
		x /= 2;

	return x == 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int64_t x;
		scanf("%lld", &x);
		printf("%s\n", is_power_of_two(x) ? "NO" : "YES");
	}
}
