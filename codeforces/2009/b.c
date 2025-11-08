#include <stdio.h>
#include <string.h>

int get_index(char *s) {
	size_t len = strlen(s);
	for (size_t i = 0; i < len; i++)
		if (s[i] == '#')
			return i + 1;
	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		char row[n][4 + 1];
		for (int i = 0; i < n; i++)
			scanf("%s", row[i]);
		for (int i = n - 1; i >= 0; i--)
			printf("%d%s", get_index(row[i]), i == 0 ? "\n" : " ");
	}
}
