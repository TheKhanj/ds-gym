#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_PRIMES (2000100)

bool is_prime[MAX_PRIMES];
// #define TEST

uint64_t my_sqrt(uint64_t x) {
	uint64_t l = 1, r = x + 1;
	while (l != r - 1) {
		uint64_t mid = (l + r) / 2;
		if (mid * mid <= x) {
			l = mid;
		} else {
			r = mid;
		}
	}

	return l;
}

void fill_primes(bool *is_prime, uint64_t size) {
	is_prime[0] = false;
	is_prime[1] = false;
	for (uint64_t i = 0; i < size; ++i) {
		is_prime[i] = true;
	}
	for (uint64_t i = 2; i < size; ++i) {
		if (is_prime[i]) {
			for (uint64_t j = i * 2; j < size; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

#ifdef TEST
int main() {
	fill_primes(is_prime, MAX_PRIMES);
	for (int i = 1; i < 10; ++i) {
		printf("%d: %d\n", i, is_prime[i]);
		fflush(stdout);
	}
}
#else
int main() {
	int n;
	scanf("%d", &n);

	fill_primes(is_prime, MAX_PRIMES);

	while (n--) {
		uint64_t x;
		scanf("%llud", &x);

		uint64_t _sqrt = my_sqrt(x);

		printf("%s\n",
					 x != 1 && (_sqrt * _sqrt == x) && is_prime[_sqrt] ? "YES" : "NO");
	}
}
#endif
