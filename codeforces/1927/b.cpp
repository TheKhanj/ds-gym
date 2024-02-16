#include <map>
#include <stdio.h>
#include <vector>

void test_case() {
	int n;
	scanf("%d", &n);
	std::map<int, std::vector<int>> mp;
	char s[n + 1];
	s[n] = '\0';

	int uniq = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			s[i] = 'a' + uniq;
			mp[0].push_back(uniq);
			uniq++;
		} else {
			int v = *--mp[a - 1].end();
			mp[a - 1].pop_back();
			mp[a].push_back(v);
			s[i] = v + 'a';
		}
	}

	printf("%s\n", s);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
