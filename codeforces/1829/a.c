#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int len = 0, maxlen = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x == 0)
			len++;
		else
			len = 0;
		if (len > maxlen) {
			maxlen = len;
		}
	}
	printf("%d\n", maxlen);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
