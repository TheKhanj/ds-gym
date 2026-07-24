#include <stdio.h>

int get_val(char *s) { return (26 * ((*s) - 'A')) + (s[1] - 'A'); }

int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int len = 26 * 26;
	int count[26 * 26];
	for (int i = 0; i < len; i++)
		count[i] = 0;
	int max = 0, max_i = 0;
	for (int i = 0; i < n - 1; i++) {
		int x = get_val(s + i);
		count[x]++;

		if (count[x] >= max) {
			max_i = i;
			max = count[x];
		}
	}

	s[max_i + 2] = 0;
	printf("%s\n", s + max_i);
}
