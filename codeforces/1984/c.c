#include <stdio.h>

#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long mx(long long *arr, int n) {
	long long ret = arr[0];
	for (int i = 0; i < n; i++)
		ret = MAX(arr[i], ret);
	return ret;
}
long long mn(long long *arr, int n) {
	long long ret = arr[0];
	for (int i = 0; i < n; i++)
		ret = MIN(arr[i], ret);
	return ret;
}

void test() {
	int n;
	scanf("%d", &n);
	long long arr[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);
	long long max[n], min[n];
	max[0] = ABS(arr[0]);
	min[0] = arr[0];

	for (int i = 1; i < n; i++) {
		long long pos[] = {
				max[i - 1] + arr[i],
				ABS(max[i - 1] + arr[i]),
				min[i - 1] + arr[i],
				ABS(min[i - 1] + arr[i]),
		};
		max[i] = mx(pos, 4);
		min[i] = mn(pos, 4);
	}

	// for (int i = 0; i < n; i++)
	// 	printf("%d %ld %ld\n", i, min[i], max[i]);

	printf("%lld\n", max[n - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
