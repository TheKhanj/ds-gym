#include <stdint.h>
#include <stdio.h>

#define MAX(x, y) x > y ? x : y

int32_t main() {
	int32_t n;
	scanf("%d", &n);
	int32_t arr[n];

	int32_t ans = 1, curr = 0;
	for (int32_t i = 0; i < n; i++) {
		scanf("%d", arr + i);

		if (i > 0 && arr[i] < arr[i - 1]) {
			curr = 1;
		} else {
			curr++;
			ans = MAX(ans, curr);
		}
	}

	printf("%d", ans);
}
