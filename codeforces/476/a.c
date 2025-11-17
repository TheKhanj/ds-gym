#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int l = (n / 2) + (n % 2);
	int x = (m - (l % m)) + l;
	printf("%d\n", l % m == 0 ? l : x <= n ? x : -1);
}
