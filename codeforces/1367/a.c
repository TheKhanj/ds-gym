#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[101];
		scanf("%s", s);
		const int sz = strlen(s);
		printf("%c", s[0]);
		for (int i = 1; i < sz; i += 2) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
}
