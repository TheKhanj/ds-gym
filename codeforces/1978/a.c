#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int a[n];
		long long mx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			if (i < n - 1)
				mx = MAX(mx, a[i]);
		}
		long long ans = (long long)(a[n - 1]) + mx;
		printf("%lld\n", ans);
	}
}
