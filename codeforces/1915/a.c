#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", a == b ? c : a == c ? b : a);
	}
}
