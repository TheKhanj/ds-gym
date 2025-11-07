#include <stdio.h>

int get_char_pos(char *s) {
	int n = 8;

	for (int i = 0; i < n; i++)
		if (s[i] != '.')
			return i;

	return n;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[8][8 + 1];
		for (int i = 0; i < 8; i++)
			scanf("%s", s[i]);

		int n = 8;

		char ans[9];
		int sz = 0;
		for (int i = 0; i < n; i++) {
			char *row = s[i];
			int j = get_char_pos(row);
			if (j == n)
				continue;
			ans[sz++] = row[j];
		}
		ans[sz] = '\0';
		printf("%s\n", ans);
	}
}
