#include <stdio.h>

void test_case() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", (m / 2) * n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
