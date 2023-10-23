#include <stdio.h>

int get_ans(int n) {
	int dig = n % 10;
	int ret = 0;
	for (int i = 1; i < dig; i++) {
		int x = i;
		int digits = 1;
		int count = 0;
		while (x <= 10000) {
			count += digits;
			x = x * 10 + i;
			digits++;
		}

		ret += count;
	}

	int digits = 1;
	while (n) {
		n /= 10;
		ret += digits;
		digits++;
	}

	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", get_ans(n));
	}
}
