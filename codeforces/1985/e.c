#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmp(const void *a, const void *b) {
	return *(long long *)a - *(long long *)b;
}

void test() {
	long long d[3], k;
	long long ans = 0;
	scanf("%lld %lld %lld %lld", d, d + 1, d + 2, &k);
	qsort(d, 3, sizeof(d[0]), cmp);
	for (long long a = 1; a <= d[0]; a++)
		for (long long b = 1; b <= d[1]; b++) {
			if (k % (a * b))
				continue;
			long long c = k / (a * b);
			if (c > d[2])
				continue;

			ans = MAX(ans, (d[0] - a + 1) * (d[1] - b + 1) * (d[2] - c + 1));
		}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test();
}
