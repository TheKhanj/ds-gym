#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_N 3e9 + 100

typedef bool (*bs_compare)(void *state, uint64_t pos);
typedef void *bs_compare_state;

static uint64_t binary_search(uint64_t left, uint64_t right,
							  bs_compare is_possible, bs_compare_state state) {
	if (left == right - 1) {
		return right;
	}

	uint64_t mid = (left + right) / 2;
	if (is_possible(state, mid)) {
		return binary_search(left, mid, is_possible, state);
	}
	return binary_search(mid, right, is_possible, state);
}

static uint64_t get_incremental_sum(uint64_t x) { return (x * (x + 1)) / 2; }

static bool is_possible(void *state, uint64_t pos) {
	uint64_t n = *(uint64_t *)state;
	uint64_t sum;

	if (pos % 2 == 0) {
		sum = 4 * (get_incremental_sum(pos / 2) * 2) + 1;
	} else {
		sum = 4 * (get_incremental_sum(pos / 2) * 2 + pos - pos / 2);
	}

	return sum >= n;
}

static void solve(uint64_t n) {
	uint64_t ans = binary_search(0, MAX_N, is_possible, &n);
	if (n == 1) {
		printf("0\n");
		return;
	}

	printf("%" PRIu64 "\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		uint64_t n;
		scanf("%" SCNu64, &n);
		solve(n);
	}
}
