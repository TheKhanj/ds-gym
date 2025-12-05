#include <map>
#include <set>
#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 2e5 + 10;

void ans_print(int *arr, int n) {
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int get_one(int *arr, int n, int k, int *ans, int *ans_len) {
	if (n != k)
		return 0;
	if (arr[0] != 1)
		return 0;
	for (int i = 0; i < n; i++)
		if (i != 0 && arr[i] != arr[i - 1] + 1)
			return 0;
	ans[0] = 1;
	*ans_len = 1;
	return 1;
}

int get_not_one(int *arr, int n, int k, int *ans, int *ans_len) {
	std::set<int> st;
	for (int i = 0; i < n; i++)
		st.insert(arr[i]);
	std::map<int, int> vis;

	for (int i = 0; i < n; i++) {
		if (vis[arr[i]] == 1)
			continue;

		for (int j = arr[i]; j <= k; j += arr[i]) {
			if (st.count(j) == 0)
				return 0;

			vis[j] = 1;
		}

		ans[*ans_len] = arr[i];
		*ans_len = *ans_len + 1;
	}

	return 1;
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(arr[0]), cmp);

	// printf("debug: ");
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");

	int ans[2][n], ans_len[2] = {0, 0}, ok[2];
	ok[0] = get_one(arr, n, k, ans[0], ans_len + 0);
	ok[1] = get_not_one(arr, n, k, ans[1], ans_len + 1);
	if (ok[0] && ok[1]) {
		if (ans_len[0] < ans_len[1])
			ans_print(ans[0], ans_len[0]);
		else
			ans_print(ans[1], ans_len[1]);

	} else if (ok[0])
		ans_print(ans[0], ans_len[0]);
	else if (ok[1])
		ans_print(ans[1], ans_len[1]);
	else
		printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
