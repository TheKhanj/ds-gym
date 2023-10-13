#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long ans = 0;

void debug_row(int *row, int n) {
	printf("debug: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", row[i]);
	}
	printf("\n");
}

void foo(int *arr, int k, int n) {
	long long sum = 0;
	// debug_row(arr, k);
	for (int i = 0; i < n-1; i++) {
		sum += ABS((arr[i % k] - arr[(i + 1) % k]));
	}
	// printf("%lld\n",sum);

	ans = MAX(ans, sum);
}

void get_comb(int *arr, int k, int n, void foo(int *arr, int k, int n),
							int index) {
	if (index == k) {
		foo(arr, k, n);
		return;
	}

	for (int i = 1; i <= k; i++) {
		bool x = true;
		for (int j = 0; j < index; j++) {
			if (arr[j] == i) {
				x = false;
			}
		}

		if (x == false) {
			continue;
		}
		arr[index] = i;
		get_comb(arr, k, n, foo, index + 1);
	}
}

int main() {
	long long int n, k;
	scanf("%lld %lld", &k, &n);

	int arr[k];
	get_comb(arr, k, n, foo, 0);

	printf("%lld\n", ans);
}
