#include <assert.h>
#include <stdio.h>
#include <string.h>

int cmp(const char *a, const char *b, char *s1, char *s2) {
	char *x = (char *)a;
	char *y = (char *)b;

	int x_len = strlen(x);
	int y_len = strlen(y);
	int total_len = x_len + y_len;

	for (int i = 0; i < total_len; i++)
		s1[i] = i < x_len ? x[i] : y[i - x_len];
	for (int i = 0; i < total_len; i++)
		s2[i] = i < y_len ? y[i] : x[i - y_len];
	s1[total_len] = 0;
	s2[total_len] = 0;

	// printf("debug: %s, %s\n", a, b);
	// printf("debug: %s, %s, %d\n", s1, s2, strcmp(s1, s2));

	return strcmp(s1, s2);
}

void solve() {
	int n;
	scanf("%d", &n);
	char s[n][4001];
	int sum_len = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		sum_len += strlen(s[i]);
	}

	char ans[sum_len + 1];
	int ans_len = 0;
	ans[0] = 0;
	for (int i = 0; i < n; i++) {
		int len = strlen(s[i]);
		char ret[2][len + ans_len + 1];
		if (cmp(ans, s[i], ret[0], ret[1]) < 0)
			strcpy(ans, ret[0]);
		else
			strcpy(ans, ret[1]);

		ans_len += len;
	}
	printf("%s\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
