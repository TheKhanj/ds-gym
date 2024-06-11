#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char l[4], r[4];
		scanf("%s %s", l, r);
		l[0] ^= r[0];
		r[0] ^= l[0];
		l[0] ^= r[0];
		printf("%s %s\n", l, r);
	}
}
