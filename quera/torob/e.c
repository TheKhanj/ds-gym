#include <stdbool.h>
#include <stdio.h>

void get_mat(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", arr + i * n + j);
		}
	}
}

void debug_row(int *row, int n) {
	printf("debug: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", row[i]);
	}
	printf("\n");
}

bool row_equal(int *row1, int *row2, int n) {
	// printf("comparing rows\n");
	// debug_row(row1, n);
	// debug_row(row2, n);
	// printf("---\n");
	for (int i = 0; i < n; i++) {
		int x = row1[i];
		bool exist = false;

		for (int j = 0; j < n; j++) {
			if (row2[j] == x) {
				exist = true;
				break;
			}
		}

		if (exist == false) {
			return false;
		}
	}

	return true;
}

bool exist_equal_row(int *row, int *mat, int n) {
	for (int i = 0; i < n; i++) {
		if (row_equal(row, mat + i * n, n)) {
			return true;
		}
	}
	return false;
}

bool exist_equal_col(int *col, int *mat, int n) {
	for (int j = 0; j < n; j++) {
		int tmp_col[n];
		for (int i = 0; i < n; i++) {
			tmp_col[i] = mat[n * i + j];
		}
		if (row_equal(col, tmp_col, n)) {
			return true;
		}
	}

	return false;
}

bool test_case() {
	int n;
	scanf("%d", &n);
	int mat1[n][n];
	int mat2[n][n];
	get_mat((int *)mat1, n);
	get_mat((int *)mat2, n);

	for (int i = 0; i < n; i++) {
		if (!exist_equal_row(mat1[i], (int *)mat2, n)) {
			return false;
		}
	}

	for (int j = 0; j < n; j++) {
		int tmp[n];
		for (int i = 0; i < n; i++) {
			tmp[i] = mat1[i][j];
		}
		if (!exist_equal_col(tmp, (int *)mat2, n)) {
			return false;
		}
	}

	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		printf("%s\n", test_case() ? "YES" : "NO");
	}
}
