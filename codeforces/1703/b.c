#include <stdbool.h>
#include <stdio.h>

int distinc_chars(char *s, int n) {
	bool has[26];
	for (int i = 0; i < 26; i++)
		has[i] = false;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (has[s[i] - 'A'] == false) {
			has[s[i] - 'A'] = true;
			ret++;
		}
	}
	return ret;
}

void solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);

	printf("%d\n", n + distinc_chars(s, n));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
