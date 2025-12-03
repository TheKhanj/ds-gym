#include <stdio.h>

int choose_immediate_break(int a, int b, int trend, int prev) {
	if (trend) {
		if (a < prev)
			return -1;
		if (b < prev)
			return 1;
		return 0;
	} else {
		if (a > prev)
			return -1;
		if (b > prev)
			return 1;
		return 0;
	}
}

int choose_two_break(int a, int b, int trend) {
	if (trend) {
		if (a > b)
			return -1;
		return 1;
	} else {
		if (a < b)
			return -1;
		return 1;
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int l = 0, r = n - 1;
	int prev = -1, trend = 1;
	char s[n + 1];
	int ssz = 0;
	while (l < r) {
		// printf("l: %d, r: %d\n", l, r);
		int immediate = choose_immediate_break(arr[l], arr[r], trend, prev);
		if (immediate == -1) {
			s[ssz++] = 'L';
			l++;
		} else if (immediate == 1) {
			s[ssz++] = 'R';
			r--;
		} else {
			int first = choose_two_break(arr[l], arr[r], trend);
			if (first == -1) {
				s[ssz++] = 'L';
				s[ssz++] = 'R';
			} else {
				s[ssz++] = 'R';
				s[ssz++] = 'L';
			}
			l++;
			r--;
		}

		if (s[ssz - 1] == 'L')
			prev = arr[l - 1];
		else
			prev = arr[r + 1];
		trend = !trend;
	}
	s[ssz++] = 'L';
	s[n] = '\0';
	// printf("ssz: %d\n", ssz);
	printf("%s\n", s);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
