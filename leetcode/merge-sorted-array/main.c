void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
	int i = 0;
	int l = 0, r = 0;
	int arr[m + n];

	while (!(l == m && r == n)) {
		if (l == m) {
			arr[i++] = nums2[r++];
			continue;
		}
		if (r == n) {
			arr[i++] = nums1[l++];
			continue;
		}
		if (nums1[l] < nums2[r])
			arr[i++] = nums1[l++];
		else
			arr[i++] = nums2[r++];
	}

	for (int i = 0; i < n + m; i++)
		nums1[i] = arr[i];
}
