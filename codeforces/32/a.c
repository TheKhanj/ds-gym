#include <stdio.h>

int decode(char **ptr) {
	if (**ptr == '.') {
		(*ptr)++;
		return 0;
	}

	(*ptr)++;
	if (**ptr == '.') {
		(*ptr)++;
		return 1;
	}

	(*ptr)++;
	return 2;
}

int main() {
	char s[201];
	char *ptr = s;
	scanf("%s", s);

	while (*ptr != 0) {
		printf("%d", decode(&ptr));
	}
}
