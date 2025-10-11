#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%s\n", (n % 2020 <= n / 2020) ? "YES" : "NO");
	}
}
