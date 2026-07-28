#include <stdio.h>

int can_ski(int temp, int threshold) { return temp <= threshold; }

void solve() {
	int n, k, q;
	scanf("%d %d %d", &n, &k, &q);
	int temp[n];
	for (int i = 0; i < n; i++)
		scanf("%d", temp + i);

	long long ans = 0;
	for (int i = 0; i < n;) {
		if (!can_ski(temp[i], q)) {
			i++;
			continue;
		}

		int j = i;
		while (j < n && can_ski(temp[j], q))
			j++;
		long long len = j - i;
		long long x = len - k + 1;

		// printf("i: %d, len: %lld, x: %lld\n", i, len, x);

		ans += x <= 0 ? 0 : (x + 1) * x / 2;

		i = j;
	}

	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
