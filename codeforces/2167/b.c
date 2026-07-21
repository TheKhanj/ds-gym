#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_cmp(const void *a, const void *b) {
	char x = *(char *)a;
	char y = *(char *)b;

	return x < y ? -1 : x > y ? 1 : 0;
}

void solve() {
	int n;
	scanf("%d", &n);
	char s[n], t[n];
	scanf("%s %s", s, t);
	qsort(s, n, sizeof(s[0]), char_cmp);
	qsort(t, n, sizeof(t[0]), char_cmp);

	printf("%s\n", strcmp(s, t) == 0 ? "YES" : "NO");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
