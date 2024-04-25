#define MIN(a, b) (a) < (b) ? (a) : (b)

int removeDuplicates(int *arr, int n) {
	int cnt = 0;
	for (int i = 0; i < n;) {
		int x = arr[i];
		int dups = 0;

		while (i < n && arr[i] == x) {
			dups++;
			i++;
		}

		dups = MIN(dups, 2);

		while (dups--)
			arr[cnt++] = x;
	}

	return cnt;
}
