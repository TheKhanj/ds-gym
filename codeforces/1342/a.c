#include <stdio.h>

#define ABS(a) ((a) < 0 ? -(a) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void solve() {
	long long x, y;
	scanf("%lld %lld", &x, &y);
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if (x < 0) {
		x = -x;
		y = -y;
	}
	long long ans;
	if (b >= 2 * a || y < 0)
		ans = a * (ABS(x) + ABS(y));
	else {
		y = ABS(y);
		long long min = MIN(x, y);
		long long max = MAX(x, y);
		ans = min * b + (max - min) * a;
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
