#include <assert.h>
#include <stdio.h>

int get_digits(int a) {
	int ret = 0;
	while (a) {
		a >>= 1;
		ret++;
	}
	return ret;
}

void solve() {
	int a, b;
	scanf("%d %d", &a, &b);
	int diff = a ^ b;
	if (diff == 0) {
		printf("0\n");
		return;
	}
	if (diff <= a) {
		printf("1\n%d\n", diff);
		return;
	}
	int dd = get_digits(diff);
	if (dd > get_digits(a)) {
		printf("-1\n");
		return;
	}

	int x = 1 << (dd - 1), y = diff ^ x;
	assert(x <= a);
	assert(y <= a);
	printf("2\n%d %d\n", y, x);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
