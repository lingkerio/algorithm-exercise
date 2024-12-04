#include <iostream>

int a[20];

bool b[20], c[40], d[40];

int n, total;

void dfs(int i) {
  if (i > n) {
    total++;
    if (total <= 3) {
      for (int i = 1; i <= n; i++) {
        std::cout << a[i] << ' ';
      }
      std::cout << '\n';
    }

    return;
  }

  for (int j = 1; j <= n; j++) {
    if ((!b[j]) && (!c[i + j]) && (!d[i - j + n])) {
      a[i]         = j;
      b[j]         = true;
      c[i + j]     = true;
      d[i - j + n] = true;
      dfs(i + 1);
      b[j]         = false;
      c[i + j]     = false;
      d[i - j + n] = false;
    }
  }
}
int main() {
  std::cin >> n;
  dfs(1);
  std::cout << total;
}