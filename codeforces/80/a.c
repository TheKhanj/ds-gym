#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = n + 1; i < m; i++)
		if (is_prime(i)) {
			printf("NO\n");
			return 0;
		}

	printf("%s\n", is_prime(m) ? "YES" : "NO");
}
