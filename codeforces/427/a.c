#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int polices = 0, crimes = 0;
	while (n--) {
		int x;
		scanf("%d", &x);

		if (x < 0) {
			if (polices <= 0) {
				crimes++;
			} else {
				polices--;
			}
		} else {
			polices += x;
		}
	}

	printf("%d", crimes);
}
