#include <map>
#include <set>
#include <stdio.h>
void test() {
	int n;
	scanf("%d", &n);

	int arr[n];
	std::map<int, int> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		arr[i] += i + 1;
		mp[arr[i]]++;
	}

	std::set<int> ans;

	while (mp.begin() != mp.end()) {
		auto it = --mp.end();
		ans.insert((*it).first);
		if ((*it).second == 1) {
			mp.erase(it);
		} else {
			mp.erase(it);
			mp[(*it).first - 1] += (*it).second - 1;
		}
	}

	while (ans.begin() != ans.end()) {
		auto it = --ans.end();
		printf("%d ", *it);
		ans.erase(it);
	}

	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
