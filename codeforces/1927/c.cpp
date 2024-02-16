#include <set>
#include <stdbool.h>
#include <stdio.h>

bool test_case() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	std::set<int> st[2];

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		st[0].insert(a);
	}

	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		st[1].insert(a);
	}

	int in0 = 0, in1 = 0, inboth = 0;
	for (int i = 1; i <= k; i++) {
		bool isin0 = st[0].find(i) != st[0].end();
		bool isin1 = st[1].find(i) != st[1].end();

		if (!isin0 && !isin1)
			return false;
		if (isin0 && !isin1)
			in0++;
		if (isin1 && !isin0)
			in1++;
		if (isin0 && isin1)
			inboth++;
	}

	return (in0 + inboth >= k / 2) && (in1 + inboth >= k / 2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		bool ans = test_case();
		printf("%s\n", ans ? "YES" : "NO");
	}
}
