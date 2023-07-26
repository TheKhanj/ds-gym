#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

struct poly_t {
	char *name;
	int64_t faces;
};

struct poly_t polies[] = {
		{.name = "Tetrahedron", .faces = 4},	{.name = "Cube", .faces = 6},
		{.name = "Octahedron", .faces = 8},		{.name = "Dodecahedron", .faces = 12},
		{.name = "Icosahedron", .faces = 20},

};

struct poly_t *get_poly(char *name) {
	for (int i = 0; i < SIZE(polies); ++i) {
		struct poly_t *poly = polies + i;
		if (strcmp(poly->name, name) == 0) {
			return poly;
		}
	}

	return NULL;
}

int main() {
	int n;
	scanf("%d", &n);
	char s[100];

	int ans = 0;
	while (n--) {
		scanf("%s", s);
		struct poly_t *poly = get_poly(s);
		ans += poly->faces;
	}

	printf("%d\n", ans);
}
