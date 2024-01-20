#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_square(char *s, int n) {
	if (n % 2 != 0)
		return false;

	for (int i = 0, j = n / 2; j < n; j++, i++)
		if (s[i] != s[j])
			return false;

	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	char s[101];
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);
		printf("%s\n", is_square(s, n) ? "YES" : "NO");
	}
}
