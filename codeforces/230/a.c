#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct dragon_t {
	int power, bonus;
	bool defeated;
};

void dragon_init(struct dragon_t *dragon) { dragon->defeated = false; }

int dragons_cmp(const void *a, const void *b) {
	return ((struct dragon_t *)a)->power - ((struct dragon_t *)b)->power;
}

struct dragon_t *select_dragon(int kirito_power, struct dragon_t *dragons,
															 int n) {
	struct dragon_t *chosen_one = NULL;
	for (struct dragon_t *dragon = dragons; dragon < dragons + n; ++dragon) {
		if (dragon->power < kirito_power && dragon->defeated == false) {
			if (chosen_one == NULL || (dragon->bonus >= chosen_one->bonus)) {
				chosen_one = dragon;
			}
		}
	}

	return chosen_one;
}

bool solve(struct dragon_t *dragons, int n, int kirito_power) {

	int defeated_count = 0;
	int i = 0;
	while (defeated_count < n) {
		struct dragon_t *defeating_dragon = select_dragon(kirito_power, dragons, n);

		if (defeating_dragon == NULL) {
			return false;
		}

		defeating_dragon->defeated = true;
		kirito_power += defeating_dragon->bonus;
		defeated_count++;
	}

	return true;
}

int main() {
	int kirito_power, n;
	scanf("%d %d", &kirito_power, &n);

	struct dragon_t dragons[n];
	for (int i = 0; i < n; ++i) {
		struct dragon_t *dragon = dragons + i;
		dragon_init(dragon);
		scanf("%d %d", &dragon->power, &dragon->bonus);
	}

	qsort(dragons, n, sizeof(dragons[0]), dragons_cmp);

	printf("%s\n", solve(dragons, n, kirito_power) == true ? "YES" : "NO");
}
