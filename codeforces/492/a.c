#include <stdbool.h>
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int h = 0;
	for (int i = 1;; i++) {
		int cost = (i * (i + 1)) / 2;
		if (n >= cost) {
			h++;
			n -= cost;
		} else {
			break;
		}
	}
	printf("%d\n", h);
}
