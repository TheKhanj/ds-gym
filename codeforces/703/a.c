#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int count = 0;
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == b)
			continue;
		count += (a > b ? 1 : -1);
	}

	if (count == 0) {
		printf("Friendship is magic!^^\n");
	} else if (count > 0) {
		printf("Mishka\n");
	} else {
		printf("Chris\n");
	}
}
