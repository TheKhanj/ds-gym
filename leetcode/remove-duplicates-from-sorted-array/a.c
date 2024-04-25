int removeDuplicates(int *arr, int n) {
	int cnt = 0;

	for (int i = 0; i < n;) {
		int x = arr[i];
		while (i < n && arr[i] == x)
			i++;

		arr[cnt++] = x;
	}

	return cnt;
}
