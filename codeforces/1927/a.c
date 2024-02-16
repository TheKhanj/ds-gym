#include <stdio.h>
#include <string.h>

int first_black(char *s) {
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] == 'B')
			return i;
	return -1;
}
int last_black(char *s) {
	int n = strlen(s);
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == 'B')
			return i;
	return -1;
}

void test_case() {
	char s[12];
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int l = first_black(s);
	int r = last_black(s);
	if (l == -1) {
		printf("0\n");
		return;
	}
	printf("%d\n", r - l + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		test_case();
}
