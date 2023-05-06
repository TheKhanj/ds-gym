#include <stdint.h>
#include <stdio.h>

int32_t main() {
	int32_t n;
	char s[50];
	scanf("%d", &n);
	scanf("%s", s);

	int32_t ans = 0;
	for (int32_t i = 0; i < n;) {
		char first = s[i];
		ans--;
		while (first == s[i]) {
			i++;
			ans++;
		}
	}

	printf("%d", ans);
}
