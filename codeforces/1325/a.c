#include <stdio.h>

void solve() {
	int x;
	scanf("%d", &x);
	printf("1 %d\n", x - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
