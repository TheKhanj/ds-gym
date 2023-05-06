#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	int32_t sum = 0;
	for (int i = 0; i < n; i++) {
		int32_t x;
		scanf("%d", &x);
		sum += x;
	}

	double ans = (double)sum / (double)n;

	printf("%.4f", ans);
}
