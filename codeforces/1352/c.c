#include <stdio.h>

void run_test() {
	int k, n;
	scanf("%d %d", &n, &k);
	int cross = k / (n - 1);
	int div = k % (n - 1);
	printf("%d\n", cross * n + (div == 0 ? -1 : div));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		run_test();
}
