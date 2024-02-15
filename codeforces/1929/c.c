#include <stdbool.h>
#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

bool test_case() {
	long long k, x, a;
	scanf("%lld %lld %lld", &k, &x, &a);
	long long debth = 0;

	for (int i = 0; i <= x; i++) {
		int min = debth / (k - 1) + (debth % (k - 1) == 0 ? 1 : 1);
		int chosen = MAX(1, min);
		// printf("step: %d\n", chosen);
		debth += chosen;

		if (debth > a)
			return false;
	}
  // printf("debug: %lld\n", debth);

	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		bool ans = test_case();
		printf("%s\n", ans ? "YES" : "NO");
	}
}
