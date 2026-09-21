#include <stdio.h>

typedef struct {
	int x, y;
} pos_t;

void pos_input(pos_t *pos) { scanf("%d %d", &pos->x, &pos->y); }

void pos_moves(pos_t *pos, pos_t moves[8], int a, int b) {
	for (int i = 0, x = -1; x <= 1; x += 2)
		for (int y = -1; y <= 1; y += 2) {
			moves[i].x = pos->x + x * a;
			moves[i++].y = pos->y + y * b;

			moves[i].x = pos->x + x * b;
			moves[i++].y = pos->y + y * a;
		}
}

void pos_print(pos_t *pos) {
	fprintf(stderr, "x: %d, y: %d\n", pos->x, pos->y);
}

void moves_print(pos_t moves[8]) {
	for (int i = 0; i < 8; i++)
		pos_print(moves + i);
}

int pos_equal(pos_t *a, pos_t *b) { return a->x == b->x && a->y == b->y; }

int pos_intersections(pos_t a[8], pos_t b[8]) {
	pos_t inter[8];
	int len = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if (!pos_equal(a + i, b + j))
				continue;
			int uniq = 1;
			for (int x = 0; x < len; x++)
				if (pos_equal(inter + x, a + i))
					uniq = 0;

			if (uniq)
				inter[len++] = a[i];
		}

	return len;
}

void solve() {
	int a, b;
	scanf("%d %d", &a, &b);
	pos_t k, q;
	pos_input(&k);
	pos_input(&q);

	pos_t k_knights[8], q_knights[8];
	pos_moves(&k, k_knights, a, b);
	pos_moves(&q, q_knights, a, b);

	// fprintf(stderr, "king:\n");
	// moves_print(k_knights);
	// fprintf(stderr, "\n");

	// fprintf(stderr, "queen:\n");
	// moves_print(q_knights);
	// fprintf(stderr, "\n");

	int n = pos_intersections(k_knights, q_knights);
	printf("%d\n", n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}
