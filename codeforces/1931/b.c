#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void test_case() {
	int n;
	scanf("%d", &n);
	int arr[n];

	int64_t sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}

	int avg = sum / n;
	int64_t lower = 0, upper = 0;
	bool is_possible = true;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > avg)
			upper += arr[i] - avg;
		if (arr[i] < avg)
			lower += avg - arr[i];
		if (upper > lower) {
			is_possible = false;
			break;
		}
	}
	printf("%s\n", is_possible ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
