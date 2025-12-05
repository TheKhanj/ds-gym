#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve() {
	int n;
	scanf("%d", &n);
	int arr[2][n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr[0] + i);
	for (int i = 0; i < n; i++)
		scanf("%d", arr[1] + i);
	long long max[n], min[n];
	for (int i = 0; i < n; i++) {
		long long a = arr[0][i];
		long long b = arr[1][i];

		long long mx = i == 0 ? 0 : max[i - 1];
		long long mn = i == 0 ? 0 : min[i - 1];
		max[i] = MAX(mx - a, b - mn);
		min[i] = MIN(mn - a, b - mx);
	}
	printf("%lld\n", max[n - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
