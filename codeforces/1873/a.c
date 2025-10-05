#include <stdio.h>

int count_onplace(char *s) {
	char c = 'a';
	int cnt = 0;
	for (int i = 0; i < 3; i++, c++) {
		if (s[i] == c) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	char s[4];
	while (n--) {
		scanf("%s", s);
		int onplace = count_onplace(s);
		printf("%s\n", onplace >= 1 ? "YES" : "NO");
	}
}
