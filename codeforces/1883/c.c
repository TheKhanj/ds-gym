#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	int arr[n];
	int min = 5, even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		int x = k - arr[i] % k;
		if (x == k)
			x = 0;
		min = MIN(min, x);

		even += arr[i] % 2 == 0 ? 1 : 0;
		odd += arr[i] % 2 == 1 ? 1 : 0;
	}

	if (k == 4) {
		int x = even >= 2 ? 0
			: (even >= 1 && odd >= 1) ? 1
			: odd >= 2 ? 2 : 5;
		min = MIN(x, min);
	}
	printf("%d\n", min);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
