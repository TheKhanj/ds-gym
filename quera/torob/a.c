#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int pos = 0;
	int a, b;
	while (n--) {
		scanf("%d %d", &a, &b);
		a--;
		b--;
		if (a == pos) {
			pos = b;
		} else if (b == pos) {
			pos = a;
		}
	}

	printf("%d\n", pos + 1);
}
