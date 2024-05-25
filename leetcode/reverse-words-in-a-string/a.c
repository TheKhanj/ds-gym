#include <stdio.h>
#include <string.h>

void remove_extra_spaces(char *s, int n) {
	int shift = 0;
	int index = 0;
	while (index < n && s[index] == ' ') {
		index++;
		shift++;
	}
	while (index < n) {
		while (index < n && s[index] != ' ') {
			s[index - shift] = s[index];
			index++;
		}
		while (index < n && s[index] == ' ') {
			index++;
			shift++;
		}
		s[index - shift] = ' ';
		shift--;
	}

	s[index - shift - 1] = '\0';
}

void reverse_range(char *s, int n) {
	for (int i = 0; i * 2 < n; i++) {
		char c = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = c;
	}
}

void reverse_all_words(char *s, int n) {
	int prev = -1, curr = 0;
	while (curr < n) {
		while (curr < n && s[curr] != ' ')
			curr++;

		reverse_range(s + prev + 1, curr - 1 - prev);

		prev = curr++;
	}
}

char *reverseWords(char *s) {
	int n = strlen(s);
	remove_extra_spaces(s, n);
	n = strlen(s);

	reverse_all_words(s, n);
	reverse_range(s, n);
	return s;
}

void test() {
	char s[] = "  hello    world  world2";
	reverseWords(s);

	printf("%s\n", s);
}

// int main() { test(); }
