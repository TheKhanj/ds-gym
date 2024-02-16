#include <set>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void test_case() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(arr[0]), cmp);

	std::set<int> st;
	int beg = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		st.insert(arr[i]);
		while (*--st.end() - *st.begin() >= n)
			st.erase(st.begin());
		ans = MAX(ans, st.size());
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
