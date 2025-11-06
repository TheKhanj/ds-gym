#include <assert.h>
#include <set>
#include <stdio.h>

void binary_split(std::multiset<int> *v, int n) {
	for (int x = 1 << 30; x; x /= 2) {
		if (n < x)
			continue;
		assert(n);
		n -= x;
		v->insert(x);
	}
}

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);

	std::multiset<int> v;
	binary_split(&v, n);

	while ((int)v.size() != k) {
		auto top = --v.end();
		int max = *top;
		v.erase(top);

		v.insert(max / 2);
		v.insert(max / 2);
	}

	for (auto it = v.begin(); it != v.end(); it++)
		printf("%d ", *it);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
