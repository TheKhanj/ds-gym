#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	assert(!(a == 0 && b == 0));

	while (b) {
		a = a % b;
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return a;
}

typedef struct range_t {
	int *arr;
	int n;

	int (*gcd)[31];
} range_t;

int range_gcd(range_t *this, size_t l, size_t r) {
	assert(l <= (size_t)this->n);
	assert(r <= (size_t)this->n);
	assert(l < r);

	int ret = this->arr[l];
	for (int jump = 30; jump >= 0; jump--)
		if ((1 << jump) & (r - l)) {
			// printf("jumping: l: %lu, r: %lu, jump: %d, gcd: %d\n", l, r, jump,
			//  		 this->gcd[l][jump]);
			ret = gcd(ret, this->gcd[l][jump]);
			l += 1 << jump;
		}

	return ret;
}

void range_init(range_t *this, int *arr, int n) {
	this->arr = arr;
	this->n = n;
	this->gcd = malloc(sizeof(int) * 31 * this->n);

	for (int i = n - 1; i >= 0; i--) {
		for (int jump = 0; jump < 31; jump++) {
			int next = i + (1 << jump);
			if (next > this->n) {
				this->gcd[i][jump] = -1;
				// printf("setting i: %d, jump: %d to -1\n", i, jump);
				continue;
			}

			assert(next <= this->n);

			if (jump == 0)
				this->gcd[i][jump] = arr[i];
			else
				this->gcd[i][jump] = gcd(this->gcd[i][jump - 1],
																 this->gcd[i + (1 << (jump - 1))][jump - 1]);

			// printf("gcd[%d][%d]: %d\n", i, jump, this->gcd[i][jump]);
		}
	}
}

void test_range_gcd(range_t *this) {
	printf("all: %d\n", range_gcd(this, 0, this->n));
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int gcd_all;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);

		gcd_all = i == 0 ? arr[i] : gcd(gcd_all, arr[i]);
	}
	for (int i = 0; i < n; i++)
		arr[i] /= gcd_all;

	range_t r;
	range_init(&r, arr, n);

	// printf("gcd_all: %d\n", gcd_all);

	// test_range_gcd(&r);
	// return 0;

	long long ans = (long long)(gcd_all);
	for (int i = 0; i < n; i++) {
		long long g;
		if (i == 0)
			g = range_gcd(&r, 1, n);
		else if (i == n - 1)
			g = range_gcd(&r, 0, n - 1);
		else
			g = gcd(range_gcd(&r, 0, i), range_gcd(&r, i + 1, n));
		ans *= g;
	}
	printf("%lld\n", ans);
}
