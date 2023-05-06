#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;

	scanf("%d", &n);

	bool hate = true;

	while (n--) {
		printf("%s %s ", hate ? "I hate" : "I love", n == 0 ? "it" : "that");
		hate = !hate;
	}
}
