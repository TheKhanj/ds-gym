#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

bool is_ok(long long n) {
	int64_t up = (n / 2) + (n % 2);
	int64_t down = (n / 2);

	while (down > 0 && up > 0) {
		int64_t du = up % 10;
		int64_t dd = down % 10;
		if (dd + du == 9)
			return false;
		int64_t xu = du < 5 ? 5 - du : 0;
		int64_t xd = dd < 5 ? dd + 1 : 0;
		int64_t mx = MAX(xu, xd);
		up += mx;
		down -= mx;

		if (down < 0)
			return false;

		up /= 10;
		down /= 10;
	}

	return down == 0 && up == 0;
}

void test() {
	long long n;
	scanf("%lld", &n);
	printf("%s\n", is_ok(n) ? "YES" : "NO");
}

int main2() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}

int main() { main2(); }
