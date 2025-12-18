#include <assert.h>
#include <stdio.h>

typedef long long ll;

ll ceil_div(ll a, ll b) { return a / b + (a % b != 0); }

ll score(ll x, ll d) { return x + ceil_div(d, x + 1); }

double dscore(double x, double d) { return x + d / (x + 1); }

ll ts(ll l, ll r, ll d) {
	ll m1 = l + (r - l) / 3;
	ll m2 = r - (r - l) / 3;

	double s1 = dscore(m1, d);
	double s2 = dscore(m2, d);

	if (l == r - 1)
		return l;
	if (l == r - 2)
		return dscore(l, d) < dscore(l + 1, d) ? l : l + 1;

	if (s1 < s2)
		return ts(l, m2, d);
	else if (s2 < s1)
		return ts(m1, r, d);
	else
		return ts(m1, m2, d);
}

void solve() {
	ll n, d;
	scanf("%lld %lld", &n, &d);
	ll x = ts(0, d, d);
	printf("%s\n", score(x, d) <= n ? "YES" : "NO");
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--)
		solve();
}
