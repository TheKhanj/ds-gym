#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>

void test() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	char s[m + 1];
	scanf("%s", s);
	std::set<int> st;
	int count = 0;
	std::vector<int> last;
	for (int i = 0; i < m; i++) {
		st.insert(s[i] - 'a');
		int should_clear = true;
		for (int j = 0; j < k; j++)
			if (st.find(j) == st.end())
				should_clear = false;
		if (should_clear) {
			st.clear();
			count++;
			last.push_back(s[i] - 'a');
		}
	}

	if (count >= n)
		printf("YES\n");
	else {
		printf("NO\n");
		int not_found = 0;
		for (int i = 0; i < k; i++)
			if (st.find(i) == st.end())
				not_found = i;
		for (int i = 0; i < last.size(); i++)
			printf("%c", last[i] + 'a');
		for (int i = 0; i < n - last.size(); i++)
			printf("%c", not_found + 'a');
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
