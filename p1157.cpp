#include <iostream>

int n, r;
int vis[23];
int s[23];
void dfs(int i) {
  if (i > r) {
    for (int j = 1; j <= r; j++) {
      printf("%3d", s[j]);
    }
    printf("\n");
    return;
  }

  for (int j = s[i-1]+1; j <= n - r + i; j++) {
    if (!vis[j]) {
      vis[j] = 1;
      s[i]   = j;
      dfs(i + 1);
      vis[j] = 0;
    }
  }
}

int main() {
  std::cin >> n >> r;
  dfs(1);
}