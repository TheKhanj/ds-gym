#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[4];
		scanf("%s", s);

		for (int i = 0; i < 3; i++) {
			s[i] = toupper(s[i]);
		}

		printf("%s\n", strcmp("YES", s) == 0 ? "YES" : "NO");
	}
}
