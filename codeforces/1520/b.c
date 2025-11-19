#include <stdio.h>

int get_digits(int n) {
	int ret = 0;
	while (n) {
		n /= 10;
		ret++;
	}
	return ret;
}

int get_count(int n, int dig) {
	int base = 0;
	for (int i = 0; i < dig; i++)
		base = base * 10 + 1;

	return n / base;
}

int get_ans(int n) {
	int dig = get_digits(n);
	return (dig - 1) * 9 + get_count(n, dig);
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
