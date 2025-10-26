#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[3][11];
		for (int i = 0; i < 3; i++)
			scanf("%s", s[i]);

		char ans[4] = {s[0][0], s[1][0], s[2][0], 0};

		printf("%s\n", ans);
	}
}
