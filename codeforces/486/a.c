#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int64_t n;
	scanf("%" SCNd64, &n);
	printf("%" PRId64, n / 2 + (n % 2 == 0 ? 0 : -n));
}
