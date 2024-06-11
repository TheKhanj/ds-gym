#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void test() {
	int n;
	scanf("%d", &n);
	long long max = 0;
	int ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum += a;
		max = MAX(a, max);
		if (sum == 2 * max)
			ans++;
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
