#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		int cnt2 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", arr + i);
			cnt1 += (arr[i] % 2 == 0) ? 0 : 1;
			cnt2 += (arr[i] % 2 == 1) ? 0 : 1;
		}
		char *s;
		if (cnt1 % 2 == 1)
			s = "NO";
		else if (cnt2 % 2 == 1 && cnt1 < 2)
			s = "NO";
		else
			s = "YES";
		printf("%s\n", s);
	}
}
