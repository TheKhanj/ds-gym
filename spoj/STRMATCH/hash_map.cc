// This still gets TLE. I really don't know what the solution is.
#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <unordered_map>

inline uint64_t hash(char *s) {
	char c;
	uint64_t ret = 0;
	while ((c = *s++))
		ret = c + (ret << 16) + (ret << 6) - ret;

	return ret;
}

inline void init_map(char *s, int n,
										 std::unordered_map<uint64_t, std::size_t> &cnt) {
	for (int i = 0; i < n; i++) {
		uint64_t h = 0;
		for (int sz = 0; i + sz < n; sz++) {
			char c = s[i + sz];
			h = c + (h << 16) + (h << 6) - h;
			cnt[h]++;
		}
	}
}

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	char s[n + 1];
	scanf("%s", s);

	char query[500000 + 1];
	std::unordered_map<uint64_t, std::size_t> cnt(n * n * 5);

	init_map(s, n, cnt);

	while (t--) {
		scanf("%s", query);
		printf("%" PRIu64 "\n", cnt[hash(query)]);
	}
}
