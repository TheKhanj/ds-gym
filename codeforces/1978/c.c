#include <stdio.h>

void swap(long long *l, long long *r) {
	*l ^= *r;
	*r ^= *l;
	*l ^= *r;
}

int test(long long n, long long k, long long *arr) {
	int l = 0, r = n - 1;
	while (l < r && r < n && k) {
		while (l < r && 2 * (arr[r] - arr[l]) > k)
			r--;
		if (r > l && 2 * (arr[r] - arr[l]) <= k) {
			k -= 2 * (arr[r] - arr[l]);
			swap(arr + r, arr + l);
		}
		// printf("l: %d, r: %d\n", l, r);
		l++;
		r--;
	}
	// printf("k: %lld\n", k);

	if (k)
		return 0;
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, k;
		scanf("%lld %lld", &n, &k);
		long long arr[n];
		for (int i = 0; i < n; i++)
			arr[i] = i + 1;
		int has_ans = test(n, k, arr);
		if (!has_ans) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		for (int i = 0; i < n; i++)
			printf("%lld ", arr[i]);
		printf("\n");
	}
}
