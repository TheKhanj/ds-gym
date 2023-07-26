#include <stdio.h>

#define ABS(x) (x > 0 ? x : -(x))

void solve_test() {
	int n, m, k, H;
	scanf("%d %d %d %d", &n, &m, &k, &H);

	int count = 0;
	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d", &h);

		int diff = ABS(h - H);

		if (diff % k == 0 && diff / k < m && diff / k > 0) {
			count++;
		}
	}

	printf("%d\n", count);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve_test();
	}
}
