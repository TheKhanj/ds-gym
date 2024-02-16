#include <cstdint>
#include <map>
#include <set>
#include <stdint.h>
#include <stdio.h>

void insert_possib(std::set<int64_t> *st, std::map<int, int> *mp,
									 int64_t orig = 1) {
	if (mp->end() == mp->begin()) {
		// printf("debug: %d\n", orig);
		st->insert(orig);
		return;
	}

	auto it = mp->begin();
	int x = it->first;
	int count = it->second;
	// printf("debug2: %d %d\n", x, count);
	mp->erase(it);
	int64_t cross = 1;
	for (int a = 0; a <= count; a++) {
		insert_possib(st, mp, cross * orig);
		cross *= x;
	}
	(*mp)[x] = count;
}

void possib(std::set<int64_t> *st, int64_t top) {
	if (top % 2 == 1)
		return;
	top /= 2;

	std::map<int, int> div;

	int64_t orig = top;
	for (int64_t a = 2; a * a <= orig; a++) {
		int64_t c = 0;
		while (top % a == 0) {
			top /= a;
			c++;
		}
		if (c != 0)
			div[a] = c;
	}

	if (top != 1)
		div[top] = 1;

	insert_possib(st, &div);
}

void test_case() {
	int64_t n, x;
	scanf("%lld %lld", &n, &x);
	std::set<int64_t> st;
	possib(&st, n + x - 2);
	possib(&st, n - x);
	while (st.begin() != st.end() && *st.begin() < x - 1)
		st.erase(st.begin());
	printf("%lld\n", st.size());
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
