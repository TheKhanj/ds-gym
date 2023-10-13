#include <stdio.h>

int get_division(int x) {
	if (x >= 1900)
		return 1;
	if (x >= 1600)
		return 2;
	if (x >= 1400)
		return 3;
	return 4;
}

int main() {
	int t = 0;
	scanf("%d", &t);
	while (t--) {
		int x = 0;
		scanf("%d", &x);
		printf("Division %d\n", get_division(x));
	}
}
