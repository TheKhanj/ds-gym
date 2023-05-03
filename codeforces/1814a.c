#include <stdbool.h>
#include <stdio.h>

bool solve(long long n, long long k) {
  return n % 2 == 0 || (k % 2 == 1 && n >= k);
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    printf(solve(n, k) == true ? "YES\n" : "NO\n");
  }
}
