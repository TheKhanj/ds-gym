#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	scanf("%d", &n);

	char s[n];
	scanf("%s", s);

	int32_t anton = 0, danik = 0;

	for (uint32_t i = 0; i < n; i++) {
		if (s[i] == 'A') {
			anton++;
		} else {
			danik++;
		}
	}

	if (anton == danik) {
		printf("Friendship");
		return 0;
	}

	printf("%s", anton > danik ? "Anton" : "Danik");
}
