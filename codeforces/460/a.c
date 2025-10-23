#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int socks = n, days = 0;
	while (socks) {
		days += socks;
		socks = (days / m) - ((days - socks) / m);
	}
	printf("%d\n", days);
}
