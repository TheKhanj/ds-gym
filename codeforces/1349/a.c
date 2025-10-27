#include <assert.h>
#include <stdio.h>

int gcd(int a, int b) {
	assert(!(a == 0 && b == 0));

	while (b) {
		a = a % b;
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int gcd_all;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);

		gcd_all = i == 0 ? arr[i] : gcd(gcd_all, arr[i]);
	}
	for (int i = 0; i < n; i++)
		arr[i] /= gcd_all;

	int pref[n], suff[n];
	for (int i = 0; i < n; i++)
		pref[i] = i == 0 ? arr[i] : gcd(arr[i], pref[i - 1]);
	for (int i = n - 1; i >= 0; i--)
		suff[i] = i == n - 1 ? arr[i] : gcd(arr[i], suff[i + 1]);

	long long ans = (long long)(gcd_all);
	for (int i = 0; i < n; i++) {
		long long g;
		if (i == 0)
			g = suff[i + 1];
		else if (i == n - 1)
			g = pref[i - 1];
		else
			g = gcd(suff[i + 1], pref[i - 1]);
		ans *= g;
	}
	printf("%lld\n", ans);
}
