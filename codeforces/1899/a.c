#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%s\n", n % 3 == 0 ? "Second" : "First");
	}
}
