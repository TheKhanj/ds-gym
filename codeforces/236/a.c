#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *_a, const void *_b) {
	const char a = *(char *)_a;
	const char b = *(char *)_b;

	return a - b;
}

int main() {
	char s[100];

	scanf("%s", s);
	const int size = strlen(s);

	qsort(s, size, sizeof(char), cmp);

	int ans = 0;
	for (int i = 0; i < size;) {
		char first = s[i];
		ans++;
		while (s[i] == first) {
			i++;
		}
	}

	printf("%s", ans % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
}
