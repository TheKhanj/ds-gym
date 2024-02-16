#include <stdio.h>

void test_case() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int first_diff[n];
	for (int i = 0; i < n;) {
		int initial = i;
		int s = arr[i];
		while (i < n && arr[i] == s)
			i++;
		for (int j = initial; j < i; j++)
			first_diff[j] = i;
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		int pos = first_diff[l];
		if (pos > r)
			printf("-1 -1\n");
		else
			printf("%d %d\n", l + 1, pos + 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
