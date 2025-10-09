#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char s[6];
		scanf("%s", s);
		int cnt[] = {0, 0};
		for (int i = 0; i < 5; i++)
			cnt[s[i] - 'A']++;
		printf("%c\n", cnt[0] > cnt[1] ? 'A' : 'B');
	}
}
