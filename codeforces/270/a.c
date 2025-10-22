#include <stdio.h>

int get_deg(int n) { return (n - 2) * 180; }

int is_ok(int deg) {
	for (int n = 3;; n++) {
		int d = get_deg(n);
		if (d == deg * n)
			return 1;
		if (deg * n < d)
			break;
	}

	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int deg;
		scanf("%d", &deg);
		printf("%s\n", is_ok(deg) ? "YES" : "NO");
	}
}
