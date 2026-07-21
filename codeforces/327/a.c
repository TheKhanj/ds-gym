#include <stdbool.h>
#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
	int n;
	scanf("%d", &n);
	int arr[n], zero[n];
	int ans = 0, applied = false;
	for (int r = 0; r < n; r++) {
		scanf("%d", arr + r);
		zero[r] = (arr[r] == 0 ? 1 : 0) + (r == 0 ? 0 : zero[r - 1]);

		for (int l = -1; l < r; l++) {
			int len = r - l;
			int z = zero[r] - (l == -1 ? 0 : zero[l]);
			int o = len - z;

			int gain = z - o;
			if (gain >= 0)
				applied = true;

			ans = MAX(ans, gain);
		}
	}

	if (!applied)
		printf("%d\n", n - zero[n - 1] - 1);
	else
		printf("%d\n", ans + n - zero[n - 1]);
}
