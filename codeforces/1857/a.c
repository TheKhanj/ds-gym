#include <stddef.h>
#include <stdio.h>

void run_testcase() {
	size_t n;
	scanf("%ld", &n);
	size_t odds = 0;
	for (size_t i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		odds += (x % 2 == 1);
	}
	printf("%s\n", odds % 2 == 0 ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		run_testcase();
	}
}
