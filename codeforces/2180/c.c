// what the fuck am i doing :)) i'm super dumb today :) maybe just like the
// other days, just randomly submitting, like the good old days
#include <stdio.h>

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k % 2 == 1) {
		for (int i = 0; i < k; i++)
			printf("%d ", n);
		printf("\n");
		return;
	}

	int arr[k];
	for (int i = 0; i < k; i++)
		arr[i] = 0;

	int l = k;
	for (int shift = 30; shift >= 0; shift--) {
		int bit = n >> shift & 1;

		if (bit) {
			for (int j = 0; j < k; j++) {
				// printf("first: j: %d, l: %d\n", j, l);
				arr[j] ^= (l != 0 ? j == l - 1 : j == 0) ? 0 : (1 << shift);
			}

			if (l > 0)
				l--;
		} else
			for (int j = l; j < k - (k - l) % 2; j++) {
				// printf("second(%d): j: %d, l: %d\n", shift, j, l);
				arr[j] ^= (1 << shift);
			}
	}

	for (int i = 0; i < k; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
