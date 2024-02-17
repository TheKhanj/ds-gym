#include <stdio.h>

void swap(long long *a, long long *b) {
	long long mid = *a;
	*a = *b;
	*b = mid;
}

long long get_diff(long long a, long long b) {
	long long diff = (long long)1 << 62;
	while (diff && (a & diff) == (b & diff))
		diff /= 2;
	return diff;
}

void test_case() {
	long long a, b, r;
	scanf("%lld %lld %lld", &a, &b, &r);
	if (a < b)
		swap(&a, &b);
	long long diff = get_diff(a, b);

	diff /= 2;

	for (; diff; diff /= 2) {
		if ((a & diff) == (b & diff))
			continue;
		if (diff > r)
			continue;
		if (b & diff)
			continue;
		r -= diff;
		a ^= diff;
		b ^= diff;
	}
	printf("%lld\n", a - b);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
