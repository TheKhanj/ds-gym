#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main() {
	int32_t n, m;
	scanf("%" SCNd32 " %" SCNd32, &n, &m);

	int32_t pos = 0;
	int64_t ans = 0;
	for (int32_t i = 0; i < m; ++i) {
		int32_t x;
		scanf("%" SCNd32, &x);
		x--;
		int64_t sum = x - pos;
		if (sum < 0) {
			sum += n;
		}

		ans += sum;
		pos = x;
	}

	printf("%" PRIu64 "\n", ans);
}
