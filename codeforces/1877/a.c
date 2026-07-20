#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	int sum = 0, x;
	while (--n) {
		scanf("%d", &x);
		sum += x;
	}
	printf("%d\n", -sum);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
