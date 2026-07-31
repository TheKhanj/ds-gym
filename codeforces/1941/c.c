#include <stdio.h>
#include <string.h>

int count(char *s, int n, const char *look) {
	int look_len = (int)strlen(look);
	int ret = 0;
	for (int i = 0; i < 1 + n - look_len; i++) {
		int equal = 1;
		for (int j = 0; j < look_len; j++)
			if (s[i + j] != look[j]) {
				equal = 0;
				break;
			}
		if (equal)
			ret++;
	}
	return ret;
}

void solve() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);

	const char *look[] = {"map", "pie", "mapie"};
	int map = count(s, n, look[0]);
	int pie = count(s, n, look[1]);
	int mapie = count(s, n, look[2]);

	// printf("map: %d, pie: %d, mapie: %d\n", map, pie, mapie);
	int ans = map + pie - mapie;

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
