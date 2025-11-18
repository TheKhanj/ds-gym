#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[101];
		scanf("%s", s);

		char ans[101];
		int n = strlen(s);
		ans[n] = '\0';

		for (int i = 0; i < n; i++) {
			char c = s[n - 1 - i];
			ans[i] = c == 'w' ? 'w' : c == 'p' ? 'q' : 'p';
		}
		printf("%s\n", ans);
	}
}
