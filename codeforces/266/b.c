#include <stdint.h>
#include <stdio.h>

void move(char *s, int32_t n) {
	for (int32_t i = 0; i < n; i++) {
		if (s[i] == 'B' && i < n - 1 && s[i + 1] == 'G') {
			s[i] = 'G';
			s[i + 1] = 'B';
			i++;
		}
	}
}

int32_t main() {
	int32_t n, t;
	char s[51];

	scanf("%d %d", &n, &t);
	scanf("%s", s);

	while (t--) {
		move(s, n);
	}

	printf("%s", s);
}
