#include <stdio.h>

int get_floor(int n, int x) {
	if (n <= 2)
		return 1;
	return 2 + (n - 3) / x;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d %d", &n, &x);
		printf("%d\n", get_floor(n, x));
	}
}
