#include <stdio.h>

void solve() {
	int n, m, i, j;
	scanf("%d %d %d %d", &n, &m, &i, &j);
	printf("1 1 %d %d\n", n, m);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
