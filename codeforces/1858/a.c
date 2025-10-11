#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c % 2 == 1)
			a++;

		printf("%s\n", b < a ? "First" : "Second");
	}
}
