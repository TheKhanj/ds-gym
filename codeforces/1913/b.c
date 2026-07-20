#include <stdio.h>
#include <string.h>

void solve(char *s) {
	scanf("%s", s);
	int n = strlen(s);
	int count[2][n];
	for (int i = 0; i < n; i++) {
		int t = s[i] == '0' ? 0 : 1;
		count[0][i] = i == 0 ? 0 : count[0][i - 1];
		count[1][i] = i == 0 ? 0 : count[1][i - 1];

		count[t][i]++;
	}
	for (int i = n - 1; i >= 0; i--) {
		int zero = count[0][n - 1];
		int one = count[1][n - 1];
		if (!(count[0][i] <= one && count[1][i] <= zero))
			continue;
		printf("%d\n", n - i - 1);
		return;
	}
	printf("%d\n", n);
}

int main() {
	int t;
	char s[200000 + 1];
	scanf("%d", &t);
	while (t--)
		solve(s);
}
