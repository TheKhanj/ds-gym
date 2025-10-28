#include <cstddef>
#include <cstdlib>
#include <set>
#include <stdio.h>

typedef struct range_t range_t;
struct range_t {
	size_t l, r;
};

size_t range_len(range_t *range);
typedef struct comparator_t {
	bool operator()(range_t a, range_t b) const {
		if (range_len(&a) == range_len(&b))
			return a.l < b.l;
		return range_len(&a) > range_len(&b);
	}
} comparator_t;

size_t range_len(range_t *range) { return range->r - range->l; }

void range_init(range_t *range, size_t l, size_t r) {
	range->l = l;
	range->r = r;
}

void range_solve(std::set<range_t, comparator_t> *ranges, int *ans) {
	for (int i = 1; ranges->size();) {
		auto beg = ranges->begin();
		range_t r = *beg;
		ranges->erase(beg);

		if (r.r == r.l)
			continue;

		int mid = (r.r + r.l - 1) / 2;
		ans[mid] = i++;
		if (r.l == r.r - 1)
			continue;

		range_t left, right;
		range_init(&left, r.l, mid);
		range_init(&right, mid + 1, r.r);
		ranges->insert(left);
		ranges->insert(right);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans[n];
		range_t r;
		range_init(&r, 0, n);

		std::set<range_t, comparator_t> ranges;
		ranges.insert(r);
		range_solve(&ranges, ans);
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}
