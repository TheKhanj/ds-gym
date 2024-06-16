#include <stdio.h>

typedef struct {
	int index;
	long long value;
} value_t;

void solve(long long n, long long *arr, long long *ans) {
	long long max = 0, maxi = 0;
	long long psum[n];
	for (int i = 0; i < n; i++) {
		psum[i] = i == 0 ? arr[i] : arr[i] + psum[i - 1];
		if (arr[i] > max) {
			max = arr[i];
			maxi = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == maxi) {
			ans[i] = 0;
			continue;
		}
		ans[i] = i + (psum[i] >= max ? 0 : 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, c;
		scanf("%lld %lld", &n, &c);
		long long arr[n];
		for (int i = 0; i < n; i++)
			scanf("%lld", arr + i);
		long long ans[n];
		arr[0] += c;
		solve(n, arr, ans);
		for (int i = 0; i < n; i++)
			printf("%lld ", ans[i]);
		printf("\n");
	}
}
