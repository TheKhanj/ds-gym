#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int64_t k, n, w;
	scanf("%" SCNd64 " %" SCNd64 " %" SCNd64, &k, &n, &w);

	int64_t cost = w * (w + 1) / 2 * k;
	printf("%" PRId64, cost <= n ? 0 : cost - n);
}
