#include <stdio.h>

int is_possible(int *arr, int sum) {
	if (sum % 3 != 0)
		return 0;

	for (int i = 0; i < 3; i++)
		if (arr[i] > (sum / 3))
			return 0;

	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	int arr[4];
	while (t--) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", arr + i);
			sum += arr[i];
		}
		printf("%s\n", is_possible(arr, sum) ? "YES" : "NO");
	}
}
