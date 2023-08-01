#include <stdio.h>

int main() {
	int k, r;
	scanf("%d %d", &k, &r);

	int ans = 1;
	int remain = k % 10;
	for (; ans <= 10; ++ans) {
		if (((ans * remain) % 10 == 0) || ((ans * remain) % 10 == r)) {
			break;
		}
	}

	printf("%d\n", ans);
}
