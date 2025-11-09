#include <cassert>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define CMP3(a, b) (((a) > (b)) - ((a) < (b)))

typedef struct {
	int life, sword;
} monster_t;

int get_first_zero(monster_t *monsters, int m) {
	for (int i = 0; i < m; i++) {
		monster_t monster = monsters[i];
		// printf("monster[%d]: life: %d, sword: %d\n", i, monster.life,
		// 			 monster.sword);
		if (monster.sword == 0)
			return i;
	}
	return m;
}

int monster_cmp(const void *a, const void *b) {
	monster_t *x = (monster_t *)a;
	monster_t *y = (monster_t *)b;

	if (x->sword == 0 && y->sword == 0)
		return CMP3(x->life, y->life);
	if (x->sword == 0)
		// x > y
		return +1;
	if (y->sword == 0)
		// x < y
		return -1;

	if (x->life == y->life)
		return -CMP3(x->sword, y->sword);

	return CMP3(x->life, y->life);
}

int fight_zero(monster_t *monsters, int m, int *swords, int n) {
	int ret = 0;
	int *sword = swords;
	for (int i = 0; i < m; i++) {
		monster_t monster = monsters[i];
		while (sword < swords + n && *sword < monster.life) {
			// printf("debug: sword: %d, life: %d\n", *sword, monster.life);
			sword++;
		}
		if (sword == swords + n)
			break;
		ret++;
		sword++;
	}
	return ret;
}

int fight_non_zero(monster_t *monsters, int m, int *swords, int n) {
	std::multiset<int> s, ret;
	for (int i = 0; i < n; i++)
		s.insert(swords[i]);

	int ans = 0;
	for (int i = 0; i < m; i++) {
		monster_t monster = monsters[i];
		while (s.size() && *s.begin() < monster.life) {
			ret.insert(*s.begin());
			s.erase(s.begin());
		}
		if (s.size() == 0)
			break;

		int sword = *s.begin();

		ans++;
		if (monster.sword > sword) {
			s.erase(s.begin());
			s.insert(monster.sword);
		}
	}

	while (s.size()) {
		ret.insert(*s.begin());
		s.erase(s.begin());
	}

	// printf("ret size: %lu\n", ret.size());
	// printf("n: %d\n", n);
	assert(ret.size() == (size_t)(n));

	int i = 0;
	for (auto sword = ret.begin(); sword != ret.end(); sword++, i++)
		swords[i] = *sword;

	return ans;
}

void monster_print(monster_t *m) {
	printf("life: %d, sword: %d\n", m->life, m->sword);
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	int swords[n];
	monster_t monsters[m];

	for (int i = 0; i < n; i++)
		scanf("%d", swords + i);
	for (int i = 0; i < m; i++)
		scanf("%d", &monsters[i].life);
	for (int i = 0; i < m; i++)
		scanf("%d", &monsters[i].sword);

	qsort(monsters, m, sizeof(monsters[0]), monster_cmp);

	// for (int i = 0; i < m; i++)
	// 	monster_print(monsters + i);

	int first_zero = get_first_zero(monsters, m);
	int ans = 0;
	ans += fight_non_zero(monsters, first_zero, swords, n);
	// printf("debug: %d\n", ans);
	ans += fight_zero(monsters + first_zero, m - first_zero, swords, n);
	// printf("debug: %d\n", ans);

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
