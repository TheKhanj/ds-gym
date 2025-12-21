#include <stdio.h>

#define MOD 1000000007LL

long long modpow(long long a, long long b) {
	long long res = 1;
	a %= MOD;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	int n[t], k[t];
	for (int i = 0; i < t; i++)
		scanf("%d", n + i);
	for (int i = 0; i < t; i++) {
		scanf("%d", k + i);
		printf("%lld\n", modpow(2, k[i]));
	}
}
