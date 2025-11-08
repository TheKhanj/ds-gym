#include <stdio.h>

void solve(int *arr, int n) {
	int even[n], even_len = 0;
	int odd[n], odd_len = 0;
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		if (x % 2 == 0)
			even[even_len++] = x;
		else
			odd[odd_len++] = x;
	}

	if (even_len >= 2) {
		printf("%d %d\n", even[0], even[1]);
		return;
	}

	if (even_len == 1)
		for (int i = 0; i < odd_len; i++)
			if (odd[i] < even[0] && (even[0] % odd[i]) % 2 == 0) {
				printf("%d %d\n", odd[i], even[0]);
				return;
			}

	for (int i = 0; i < odd_len; i++)
		for (int j = i - 1; j >= 0; j--)
			if ((odd[i] % odd[j]) % 2 == 0) {
				printf("%d %d\n", odd[j], odd[i]);
				return;
			}

	printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		solve(arr, n);
	}
}
