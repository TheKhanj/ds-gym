#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int last_even = -1;
	int last_odd = -1;
	int diff = 0;

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		diff += (x % 2 == 0 ? 1 : -1);
		if (x % 2 == 0) {
			last_even = i + 1;
		} else {
			last_odd = i + 1;
		}
	}

	printf("%d\n", (diff >= 0 ? last_odd : last_even));
}
