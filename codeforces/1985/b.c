#include <stdio.h>

int sum(int i, int n) {
	int x = i;
	int ret = 0;
	while (x <= n) {
		ret += x;
		x += i;
	}
	return ret;
}

void test() {
	int n;
	scanf("%d", &n);
	int ans = 2;
	for (int i = 2; i <= n; i++)
		if (sum(ans, n) < sum(i, n))
			ans = i;
	printf("%d\n", (ans));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
