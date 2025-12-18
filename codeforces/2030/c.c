#include <stdio.h>

int solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	if (s[0] == '1' || s[n - 1] == '1')
		return 1;
	for (int i = 0; i < n;) {
		if (s[i] == '0') {
			i++;
			continue;
		}

		int len = 0;
		while (i < n && s[i] == '1')
			i++, len++;

		if (len > 1)
			return 1;
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		printf("%s\n", solve() ? "YES" : "NO");
}
