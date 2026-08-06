#include <stdio.h>
#include <string.h>

void solve() {
	char s[101];
	scanf("%s", s);
	int n = strlen(s);
	int first[2];
	for (int i = 0; i < n; i++)
		if (s[i] == '0') {
			first[0] = i;
			break;
		}
	for (int i = 0; i < n; i++)
		if (s[i] == '1') {
			first[1] = i;
			break;
		}
	for (int i = 0; i < n; i++)
		if (i != first[0] && i != first[1])
			printf("%c", s[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
