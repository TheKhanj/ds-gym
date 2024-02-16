#include <stdbool.h>
#include <stdio.h>

bool test_case() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a % 2 == 1 && b % 2 == 1)
		return false;
	if (a % 2 == 0)
		if (a / 2 != b && b * 2 != a)
			return true;
	if (b % 2 == 0)
		if (b / 2 != a && a * 2 != b)
			return true;
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		bool ans = test_case();
		printf("%s\n", ans ? "Yes" : "No");
	}
}
