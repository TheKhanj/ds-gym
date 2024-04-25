#define MAX(a, b) (a) > (b) ? (a) : (b)

int maxProfit(int *arr, int n) {
	int max[n];
	for (int i = n - 1; i >= 0; i--)
		max[i] = MAX(arr[i], i == n - 1 ? 0 : max[i + 1]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = MAX(ans, max[i] - arr[i]);
	return ans;
}
