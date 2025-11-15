#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n * 2];
		int odd = 0, sum = 0;
		for (int i = 0; i < 2 * n; i++) {
			scanf("%d", arr + i);
			int x = arr[i];
			if (x % 2 == 1)
				odd++;
			sum += x;
		}

		printf("%s\n", odd >= n && (odd - n + 1) % 2 == 1 ? "YES" : "NO");
	}
}
