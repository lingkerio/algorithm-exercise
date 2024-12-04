#include <iostream>

char s[102][102];

void dfs(int x, int y) {
  s[x][y] = '.';
  int dx, dy;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      dx = x + i;
      dy = y + j;
      if (dx >= 0 && dx < 101 && dy >= 0 && dy < 101 && s[dx][dy] == 'W') {
        dfs(dx, dy);
      }
    }
  }
}

int main() {
  int n, m, ans = 0;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'W') {
        dfs(i, j);
        ans++;
      }
    }
  }

  std::cout << ans;
}