#include <stdbool.h>
#include <stdio.h>

bool dislike(int n) { return n % 3 == 0 || n % 10 == 3; }

int get_kth(int k) {
	for (int i = 1, count = 0;; i++) {
		if (dislike(i)) {
			continue;
		}
		count++;
		if (count == k) {
			return i;
		};
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int k;
		scanf("%d", &k);
		printf("%d\n", get_kth(k));
	}
}
