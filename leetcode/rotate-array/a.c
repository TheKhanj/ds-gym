void rotate(int *arr, int n, int k) {
	int ans[n];
	for (int i = 0; i < n; i++)
		ans[i] = arr[(i - k + n) % n];
	for (int i = 0; i < n; i++)
		arr[i] = ans[i];
}
