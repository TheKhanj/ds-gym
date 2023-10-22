#include <stdio.h>

void test_case() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int count[2] = {0, 0};
	int mismatches = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		count[arr[i] % 2]++;
		if (arr[i] % 2 != i % 2) {
			mismatches++;
		}
	}

	const int even = count[0];
	const int odd = count[1];

	if (even != (n + 1) / 2 || odd != n / 2) {
		printf("-1\n");
		return;
	}

	printf("%d\n", mismatches / 2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		test_case();
	}
}
