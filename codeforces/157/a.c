#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int min = -1, max = -1;
	int amazing = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		if (min == -1) {
			min = x;
			max = x;
			continue;
		}

		if (x < min) {
			min = x;
			amazing++;
		} else if (x > max) {
			max = x;
			amazing++;
		}
	}

	printf("%d", amazing);
}
