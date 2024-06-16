#include <assert.h>

int romanToInt(char *s) {
	if (*s == '\0')
		return 0;

	switch (*s) {
	case 'I':
		if (*(s + 1) == 'V')
			return romanToInt(s + 2) + 4;
		if (*(s + 1) == 'X')
			return romanToInt(s + 2) + 9;
		return romanToInt(s + 1) + 1;
	case 'V':
		return romanToInt(s + 1) + 5;
	case 'X':
		if (*(s + 1) == 'L')
			return romanToInt(s + 2) + 40;
		if (*(s + 1) == 'C')
			return romanToInt(s + 2) + 90;
		return romanToInt(s + 1) + 10;
	case 'L':
		return romanToInt(s + 1) + 50;
	case 'C':
		if (*(s + 1) == 'D')
			return romanToInt(s + 2) + 400;
		if (*(s + 1) == 'M')
			return romanToInt(s + 2) + 900;
		return romanToInt(s + 1) + 100;
	case 'D':
		return romanToInt(s + 1) + 500;
	case 'M':
		return romanToInt(s + 1) + 1000;
	}
	assert(0);
}
