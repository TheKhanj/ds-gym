#include <stdio.h>

const long long mod = 998244353;
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
	long long cnt_max[n], cnt_min[n];
	cnt_max[0] = arr[0] < 0 ? 1 : 2;
	cnt_min[0] = arr[0] < 0 ? 1 : 2;

	for (int i = 1; i < n; i++) {
		long long pos[] = {
				max[i - 1] + arr[i],
				ABS(max[i - 1] + arr[i]),
				min[i - 1] + arr[i],
				ABS(min[i - 1] + arr[i]),
		};
		max[i] = mx(pos, 4);
		min[i] = mn(pos, 4);

		long long c;
		cnt_max[i] = 0;
		c = (pos[0] == max[i]) + (pos[1] == max[i]);
		cnt_max[i] += (cnt_max[i - 1] * c) % mod;
		if ((max[i - 1] != min[i - 1])) {
			c = (pos[2] == max[i]) + (pos[3] == max[i]);
			cnt_max[i] += (cnt_min[i - 1] * c) % mod;
		}
		cnt_max[i] %= mod;

		cnt_min[i] = 0;
		c = (pos[0] == min[i]) + (pos[1] == min[i]);
		cnt_min[i] += (cnt_max[i - 1] * c) % mod;
		if ((max[i - 1] != min[i - 1])) {
			c = (pos[2] == min[i]) + (pos[3] == min[i]);
			cnt_min[i] += (cnt_min[i - 1] * c) % mod;
		}
		cnt_min[i] %= mod;
	}

	// for (int i = 0; i < n; i++)
	// 	printf("%d %ld %ld\n", i, min[i], max[i]);

	printf("%lld\n", cnt_max[n - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
