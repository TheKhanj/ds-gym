#include <stdio.h>

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	char s[n + 1];
	scanf("%s", s);
	int can = 0, slept = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (can <= i) {
				slept++;
				can = i + 1;
			}
		} else
			can = i + k + 1;
	}
	printf("%d\n", slept);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
