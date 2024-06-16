#include <assert.h>
#include <stdbool.h>
#include <string.h>

int is_open(char c) {
	switch (c) {
	case '{':
	case '[':
	case '(':
		return true;
	}
	return false;
}

int match(char open, char close) {
	switch (open) {
	case '{':
		return close == '}';
	case '[':
		return close == ']';
	case '(':
		return close == ')';
	}

	assert(false);
}

bool isValid(char *s) {
	int n = strlen(s);
	char stack[n];
	int len = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];

		if (is_open(c))
			stack[len++] = c;
		else {
			if (len == 0 || !match(stack[len - 1], c))
				return false;
			len--;
		}
	}

	return len == 0;
}

void test() { assert(isValid("[][][](){}")); }

int main() { test(); };
