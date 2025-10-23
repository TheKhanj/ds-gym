#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int count[] = {0, 0};
		while (n--) {
			int a;
			scanf("%d", &a);
			count[a % 2]++;
		}
		printf("%d\n", MIN(count[0], count[1]));
	}
}
