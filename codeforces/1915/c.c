#include <stdint.h>
#include <stdio.h>

int is_square(long long a) {
	long long l = 1, mid, r = INT32_MAX;
	while (l != r - 1) {
		mid = (l + r) / 2;
		if (mid * mid <= a)
			l = mid;
		else
			r = mid;
	}

	return a == l * l;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		long long sum = 0;
		while (n--) {
			int a;
			scanf("%d", &a);
			sum += a;
		}
		printf("%s\n", is_square(sum) ? "YES" : "NO");
	}
}
