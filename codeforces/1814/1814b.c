#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int ceil_dev(int a, int b) {
  if (a % b == 0) {
    return (int)(a / b);
  }

  return (int)(a / b) + 1;
}

void solve(int a, int b) {
  int ans = a + b;
  for (int t = 1; t <= 4 * sqrt(a + b); t++) {
    int x = ceil_dev(a, t) + ceil_dev(b, t) + t - 1;
    ans = min(ans, x);
  }

  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);

    solve(a, b);
  }
}
