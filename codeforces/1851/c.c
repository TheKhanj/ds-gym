#include <stdbool.h>
#include <stdio.h>

int get_count(int *arr, int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			count++;
		}
	}

	return count;
}

void solve_test() {
	int n, k;

	scanf("%d %d", &n, &k);
	int arr[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	int left = -1, right = -1;

	int count = k;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == arr[0]) {
			count--;
		}

		if (count == 0) {
			left = i;
			break;
		}
	}

	count = k;
	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] == arr[n - 1]) {
			count--;
		}

		if (count == 0) {
			right = i;
			break;
		}
	}

	int first_count = get_count(arr, n, arr[0]);

	bool is_ok = (arr[0] == arr[n - 1] && first_count >= k) ||
							 (left != -1 && right != -1 && left < right);

	// printf("debug: %d, %d\n", left, right);
	printf("%s\n", is_ok ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve_test();
	}
}
