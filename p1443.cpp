#include <iostream>
#include <queue>
int s[404][404];

int visit[404][404];

int x, y, n, m;

int const dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int const dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};

int main() {
  std::queue<int> c{};

  std::cin >> n >> m >> x >> y;

  c.push(x), c.push(y);
  visit[x][y] = 1;
  s[x][y] = 0;

  while (!c.empty()) {
    int xx = c.front();
    c.pop();
    int yy = c.front();
    c.pop();
    for (int i = 0; i < 8; i++) {
      int u = xx + dx[i];
      int v = yy + dy[i];
      if ((u < 1) || (u > n) || (v < 1) || (v > m) || visit[u][v]) {
        continue;
      }
      visit[u][v] = 1;
      s[u][v]     = s[xx][yy] + 1;
      c.push(u);
      c.push(v);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%-5d", visit[i][j] ? s[i][j] : -1);
    }
    printf("\n");
  }
}
