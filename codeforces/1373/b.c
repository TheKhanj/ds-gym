#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void count(char *s, int *zero, int *one) {
	int n = strlen(s);
	*zero = 0, *one = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			(*zero)++;
		else
			(*one)++;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	char s[101];
	while (t--) {
		scanf("%s", s);
		int zero, one;
		count(s, &zero, &one);
		int min = MIN(zero, one);
		printf("%s\n", min % 2 ? "DA" : "NET");
	}
}
