#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[11];
		scanf("%s", s);
		size_t sz = strlen(s);
		s[sz - 2] = 'i';
		s[sz - 1] = '\0';
		printf("%s\n", s);
	}
}
