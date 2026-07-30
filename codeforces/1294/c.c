#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[3], len = 0;
		for (int i = 2; i * i <= n && len < 2; i++)
			if (len < 2 && n % i == 0)
				n /= i, arr[len++] = i;

		if (arr[0] != n && arr[1] != n)
			arr[len++] = n;

		if (len != 3) {
			printf("NO\n");
			continue;
		}

		printf("YES\n");
		for (int i = 0; i < 3; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}
