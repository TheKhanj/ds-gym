#include <set>
#include <stdint.h>
#include <stdio.h>

int count_digits(int x) {
	int ret = 0;
	while (x) {
		x /= 10;
		ret++;
	}
	return ret;
}

int count_zero(int x) {
	int ret = 0;
	while (x && x % 10 == 0) {
		ret++;
		x /= 10;
	}
	return ret;
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	int64_t total_digits = 0;

	std::multiset<int> digits;

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int c = count_digits(a);
		total_digits += c;
		digits.insert(count_zero(a));
	}

	digits.insert(0);
	auto it = --digits.end();
	for (int i = 0; *it != 0 && i < n; i++) {
		// girl play
		int max = *it;
		total_digits -= max;
		it--;
		if (*it == 0)
			break;
		// boy play
		// saved digits, yay
		it--;
		if (*it == 0)
			break;
	}

	printf("%s\n", total_digits > m ? "Sasha" : "Anna");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
