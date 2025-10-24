#include <stdio.h>

int solve(int n, int x_adj) {
	if (x_adj <= 1)
		return 1;
	return n % 2 == 1 ? 2 : 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d %d", &n, &x);
		int x_adj = 0;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			if (u == x || v == x)
				x_adj++;
		}
		printf("%s\n", solve(n, x_adj) == 1 ? "Ayush" : "Ashish");
	}
}
