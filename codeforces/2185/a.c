#include <stdio.h>

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
