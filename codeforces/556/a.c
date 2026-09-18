#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (s[i] == '1' ? 1 : -1);
	if (cnt < 0)
		cnt = -cnt;
	printf("%d\n", cnt);
}
