#include <stdio.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		max = MAX(max, arr[i]);
		sum += arr[i];
	}

	printf("%d", n * max - sum);
}
