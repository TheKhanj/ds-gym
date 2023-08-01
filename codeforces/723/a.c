#include <stdint.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : -(a))

int32_t get_distance(int *arr, int pos) {
	int32_t ret = 0;
	for (int i = 0; i < 3; ++i) {
		ret += ABS(arr[i] - pos);
	}

	return ret;
}

int main() {
	int arr[3];
	for (int i = 0; i < 3; ++i) {
		scanf("%d", arr + i);
	}

	int sorted[3];
	sorted[0] = MIN(MIN(arr[0], arr[1]), arr[2]);
	sorted[1] = MIN(MAX(arr[0], arr[1]), arr[2]);
	sorted[2] = MAX(MAX(arr[0], arr[1]), arr[2]);

	int32_t ans = INT32_MAX;
	for (int pos = 1; pos <= 100; ++pos) {
		ans = MIN(ans, get_distance(sorted, pos));
	}

	printf("%d", ans);
}
