#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	long long x = *(const long long *)a;
	long long y = *(const long long *)b;

	return (x > y) - (x < y);
}

long long gcd(long long a, long long b) {
	if (a < b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	while (b != 0) {
		long long t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	long long arr[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);

	qsort(arr, n, sizeof(arr[0]), cmp);

	if (n == 1) {
		for (int i = 0; i < m; i++) {
			long long x;
			scanf("%lld", &x);
			printf("%lld%s", x + arr[0], i == m - 1 ? "" : " ");
		}
		return 0;
	}

	long long total_gcd = arr[1] - arr[0];
	for (int i = 0; i < n - 1; i++) {
		long long diff = arr[i + 1] - arr[i];
		if (diff == 0)
			continue;
		assert(diff > 0);
		total_gcd = gcd(diff, total_gcd);
	}
	for (int i = 0; i < m; i++) {
		long long x;
		scanf("%lld", &x);
		printf("%lld%s", gcd(x + arr[0], total_gcd), i == m - 1 ? "" : " ");
	}
	printf("\n");
	return 0;
}
