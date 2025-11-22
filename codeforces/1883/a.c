#include <stdio.h>

int is_ok(int n, int k, int odd) {
	if ((n - k) % 2 == 0)
		return k >= odd && (k - odd) % 2 == 0;

	return k >= (odd - 1) && (k - odd + 1) % 2 == 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		char s[n + 1];
		scanf("%s", s);
		int cnt[26];
		for (int i = 0; i < 26; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++)
			cnt[s[i] - 'a']++;
		int odd = 0;
		for (int i = 0; i < 26; i++)
			odd += (cnt[i] % 2 == 1);
		printf("%s\n", is_ok(n, k, odd) ? "YES" : "NO");
	}
}
