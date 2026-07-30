#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int neg = 0, pos = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x == -1)
				neg++;
			else
				pos++;

			sum += x;
		}

		int ans = 0;
		while (sum < 0 || neg % 2 == 1)
			neg--, pos++, sum += 2, ans++;
		printf("%d\n", ans);
	}
}
