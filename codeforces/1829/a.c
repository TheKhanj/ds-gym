#include <stdio.h>
#include <string.h>

int get_diff(char *s) {
	char cf[] = "codeforces";
	int ret = 0, len = strlen(cf);
	for (int i = 0; i < len; i++) {
		ret += cf[i] != s[i];
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[11];
		scanf("%s", s);
		printf("%d\n", get_diff(s));
	}
}
