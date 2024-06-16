#include <string.h>

int lengthOfLastWord(char *s) {
	int n = strlen(s);
	int len;
	for (int i = 0; i < n;) {
		len = 0;
		while (i < n && s[i++] != ' ')
			len++;
		while (i < n && s[i] == ' ')
			i++;
	}
	return len;
}
