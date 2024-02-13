#include <cstdint>
#include <map>
#include <stdint.h>
#include <stdio.h>

void solve() {
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	std::map<int, std::map<int, int>> mp;
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		int a = arr[i];
		mp[a % y][a % x]++;
	}

	int64_t ans = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		auto m = it->second;
		for (auto itt = m.begin(); itt != m.end(); itt++) {
			int div = itt->first;
			int64_t a = itt->second;
			if (div == 0 || div == x - div)
				ans += a * (a - 1) / 2;
			else {
				int64_t b = m[(x - div)];

				if (div < x - div)
					ans += b * a;
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
