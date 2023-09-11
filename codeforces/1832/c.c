#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t t;
	scanf("%d", &t);
	while (t--) {
		int32_t n;
		scanf("%d", &n);
		int64_t arr[n];

		for (int32_t i = 0; i < n; i++) {
			scanf("%" SCNd64, arr + i);
		}

		if (n == 1) {
			printf("1\n");
			continue;
		}

		int32_t i = 0;
		while (i < n && arr[i] == arr[0]) {
			i++;
		}
		if (i == n) {
			printf("1\n");
			continue;
		}
		bool direction = (arr[i] - arr[i - 1] > 0) ? true : false;

		int32_t count = 1;
		while (i < n) {
			while (i < n && (direction == true ? arr[i] >= arr[i - 1]
																				 : arr[i] <= arr[i - 1])) {
				i++;
			}
			count++;
			direction = !direction;
		}

		printf("%d\n", count);
	}
}
