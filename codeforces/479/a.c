#include <stdint.h>
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

static int32_t find_maximum_value(int32_t *beg, int32_t *end) {
	if (beg == end - 1) {
		return *beg;
	}

	int32_t ans = 0;
	for (int32_t *mid = beg + 1; mid < end; mid++) {
		int32_t left = find_maximum_value(beg, mid);
		int32_t right = find_maximum_value(mid, end);

		ans = MAX(ans, left + right);
		ans = MAX(ans, left * right);
	}

	return ans;
}

int32_t main() {
	int32_t a[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", a + i);
	}

	printf("%d", find_maximum_value(a, a + 3));
}
