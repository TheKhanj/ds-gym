#include <stdbool.h>
#include <stdio.h>

bool is_lucky(char *s) {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += s[i] - '0';
	}
	for (int i = 3; i < 6; i++) {
		sum -= s[i] - '0';
	}
	return sum == 0;
}

int main() {
	int t;
	scanf("%d", &t);
	char s[7];
	while (t--) {
		scanf("%s", s);
		printf("%s\n", is_lucky(s) ? "YES" : "NO");
	}
}
