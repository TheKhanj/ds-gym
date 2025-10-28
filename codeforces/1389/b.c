#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

void solve() {
	int n, k, z;
	scanf("%d %d %d", &n, &k, &z);

	long long arr[n], max_couple[n], sum[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr + i);

		max_couple[i] = i == 0 ? 0 : MAX(arr[i] + arr[i - 1], max_couple[i - 1]);
		sum[i] = i == 0 ? arr[i] : arr[i] + sum[i - 1];
	}

	long long ans = 0;
	for (int right = k % 2; right <= k; right += 2) {
		long long left = (k - right) / 2;
		if (left > z)
			continue;

		ans = MAX(ans, left * max_couple[right] + sum[right]);
	}
	for (int right = !(k % 2); right < k; right += 2) {
		long long left = (k - 1 - right) / 2;
		if (left >= z)
			continue;

		if (right == 0)
			continue;

		ans = MAX(ans, left * max_couple[right] + sum[right] + arr[right - 1]);
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
