#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_suspicable(char *s, int n) {
	bool vis[26];
	memset(vis, false, 26);

	for (int i = 0; i < n;) {
		char x = s[i];

		while (i < n && s[i] == x) {
			i++;
		}

		const int pos = x - 'A';

		if (vis[pos] == true) {
			return true;
		}

		vis[pos] = true;
	}

	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char s[n + 1];
		scanf("%s", s);

		printf("%s\n", is_suspicable(s, n) ? "NO" : "YES");
	}
}
