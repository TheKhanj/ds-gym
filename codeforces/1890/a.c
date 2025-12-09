#include <stdio.h>

#define ABS(a) ((a) > 0 ? (a) : -(a))

int is_possible(int *diff, int diff_len, int *arr, int n) {
	if (diff_len > 2)
		return 0;
	if (diff_len == 1)
		return 1;

	int cnt[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		int j = (arr[i] == diff[0]) ? 0 : 1;
		cnt[j]++;
	}
	return ABS(cnt[0] - cnt[1]) <= 1;
}

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	int diff[n], diff_len = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		int found = 0;
		for (int j = 0; j < diff_len; j++)
			if (diff[j] == arr[i])
				found = 1;
		if (!found)
			diff[diff_len++] = arr[i];
	}

	printf("%s\n", is_possible(diff, diff_len, arr, n) ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
