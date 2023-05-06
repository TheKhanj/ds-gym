#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int64_t n, k;

	scanf("%" SCNd64 " %" SCNd64, &n, &k);

	int64_t odd_count = n / 2 + (n % 2 == 1);

	if (k <= odd_count) {
		printf("%" PRId64, 2 * k - 1);
	} else {
		printf("%" PRId64, 2 * (k - odd_count));
	}
}
