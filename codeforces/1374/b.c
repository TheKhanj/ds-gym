#include <stdio.h>

int solve(int n) {
	int ret = 0;
	while (n % 6 == 0) {
		n /= 6;
		ret++;
	}
	while (n % 3 == 0) {
		n /= 3;
		ret += 2;
	}
	if (n == 1) {
		return ret;
	}
	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}
