#include <iostream>

int s[32][32];

void dfs(int x, int y) {
  s[x][y] = 2;
  int dx, dy;
  for (int i = -1; i <= 1; i++) {
    dx = x + i;
    dy = y;
    if (dx >= 0 && dx < 32 && dy >= 0 && dy < 32 && s[dx][dy] == 0) {
      dfs(dx, dy);
    }
  }

  for (int i = -1; i <= 1; i++) {
    dx = x;
    dy = y + i;
    if (dx >= 0 && dx < 32 && dy >= 0 && dy < 32 && s[dx][dy] == 0) {
      dfs(dx, dy);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> s[i][j];
    }
  }

  dfs(0, 0);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == 2) {
        std::cout << "0 ";
      } else if (s[i][j] == 0) {
        std::cout << "2 ";

      } else {
        std::cout << s[i][j] << " ";
      }
    }
    std::cout << '\n';
  }
}