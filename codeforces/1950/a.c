#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%s\n", (a < b && b < c)		? "STAIR"
									 : (a < b && b > c) ? "PEAK"
																			: "NONE");
	}
}
