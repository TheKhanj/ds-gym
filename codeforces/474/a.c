#include <assert.h>
#include <stdio.h>
#include <string.h>

char fix_char(char c, int shift) {
	static char keyboard[] = "qwertyuiopasdfghjkl;zxcvbnm,./\0";

	for (size_t i = 0; i < strlen(keyboard); i++)
		if (c == keyboard[i])
			return keyboard[i + shift];

	assert(0 && "unreachable code");
}

int main() {
	char c[2];
	scanf("%s", c);
	int shift = (c[0] == 'L' ? 1 : -1);
	char s[101];
	scanf("%s", s);
	for (size_t i = 0; i < strlen(s); i++)
		s[i] = fix_char(s[i], shift);
	printf("%s\n", s);
}
