#include <bits/stdc++.h>

using namespace std;
const int N = 5e6;
int n, q;
string s, p;
int trie[N][30], nxt, fim[N];

void add(int node = 0, int pos = 0) {
	fim[node]++;
	if (pos == s.size())
		return;
	if (!trie[node][s[pos] - 'a'])
		trie[node][s[pos] - 'a'] = ++nxt;
	add(trie[node][s[pos] - 'a'], pos + 1);
}

int query(int node = 0, int pos = 0) {
	if (pos == s.size())
		return fim[node];
	if (!trie[node][s[pos] - 'a'])
		return 0;
	return query(trie[node][s[pos] - 'a'], pos + 1);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	cin >> p;
	for (int i = 0; i < p.size(); i++) {
		s = p.substr(i);
		add();
	}

	while (q--) {
		cin >> s;
		cout << query() << "\n";
	}

	return 0;
}
