#include <stdio.h>

#define MaxN 5000000
int trie[MaxN][26], next = 0, count[MaxN];

void insert(int node, char *s) {
	count[node]++;
	if (*s == '\0')
		return;

	if (!trie[node][*s - 'a'])
		trie[node][*s - 'a'] = ++next;
	insert(trie[node][*s - 'a'], s + 1);
}

int query(int node, char *s) {
	if (*s == '\0')
		return count[node];
	if (!trie[node][*s - 'a'])
		return 0;
	return query(trie[node][*s - 'a'], s + 1);
}

int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	char s[n + 1];
	scanf("%s", s);

	for (int i = 0; i < n; i++)
		insert(0, s + i);

	char q[500000 + 1];
	while (t--) {
		scanf("%s", q);
		printf("%d\n", query(0, q));
	}
}
