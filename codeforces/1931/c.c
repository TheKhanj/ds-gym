#include <stdbool.h>
#include <stdio.h>

#define MIN(x, y) (x) < (y) ? (x) : (y)

int same_go(int *arr, int n) {
	int i = 0;
	while (arr[i] == arr[0])
		i++;
	return i;
}

int same_go2(int *arr, int n) {
	int i = n - 1;
	while (arr[i] == arr[n - 1])
		i--;
	return i;
}

void test_case() {
	int n;
	scanf("%d", &n);
	int arr[n];
	bool all_equal = true;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		if (arr[i] != arr[0])
			all_equal = false;
	}

	if (all_equal) {
		printf("0\n");
		return;
	}

	int left = same_go(arr, n);
	int right = same_go2(arr, n);
	if (arr[0] == arr[n - 1]) {
		printf("%d\n", right - left + 1);
		return;
	}
	printf("%d\n", MIN(right + 1, n - left));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		test_case();
	}
}
