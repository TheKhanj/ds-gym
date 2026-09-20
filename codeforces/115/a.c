#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main() {
	int n;
	scanf("%d", &n);
	int par[n], h[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", par + i);
		h[i] = -1;
		if (par[i] == -1)
			h[i] = 1;
		else
			par[i]--;
	}
	int height = 0;
	for (int i = 0; i < n; i++) {
		for (int curr = 0; curr < n; curr++) {
			int p = par[curr];
			if (p != -1 && h[p] != -1)
				h[curr] = h[p] + 1;

			height = MAX(h[curr], height);
		}
	}

	printf("%d\n", height);
}
