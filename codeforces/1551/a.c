#include <stdio.h>

void run_test() {
	int n;
	scanf("%d", &n);
	int div = n / 3;
	int mod = n % 3;
	int c1 = div + (mod == 1);
	int c2 = div + (mod == 2);
	printf("%d %d\n", c1, c2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		run_test();
}
