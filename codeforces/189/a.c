#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int get_count(int *x) {
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		ret += x[i];
	}

	return ret;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
	int n;
	scanf("%d", &n);
	int arr[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", arr + i);
	qsort(arr, 3, sizeof(arr[0]), cmp);

	int x[3];
	x[0] = n / arr[0];
	int found = 0;
	int ans = 0;

	while (x[0] >= 0) {
		int remain1 = n - (x[0] * arr[0]);
		x[1] = remain1 / arr[1];
		while (x[1] >= 0) {
			int remain2 = remain1 - x[1] * arr[1];
			x[2] = remain2 / arr[2];

			if (remain2 % arr[2] == 0) {
				ans = MAX(ans, get_count(x));
			}

			x[1]--;
		}

		x[0]--;
	}

	printf("%d\n", ans);
}
