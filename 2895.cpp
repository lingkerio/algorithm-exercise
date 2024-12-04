#include <iostream>
#include <queue>

int m, vis[305][305], ma[305][305], s[305][305];

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

int main() {
  std::cin >> m;

  for (int i = 0; i < 305; i++) {
    for (int j = 0; j < 305; j++) {
      s[i][j] = -1;
    }
  }

  for (int i = 1; i <= m; i++) {
    int x, y, t;

    std::cin >> x >> y >> t;

    for (int j = 0; j <= 4; j++) {
      if ((x + dx[j] >= 0) && (y + dy[j] >= 0) && ((s[x + dx[j]][y + dy[j]] == -1) || (s[x + dx[j]][y + dy[j]] > t))) {
        s[x + dx[j]][y + dy[j]] = t;
      }
    }
  }

  std::queue<std::pair<int, int>> q;

  q.push(std::make_pair(0, 0));

  vis[0][0] = 1;

  while (!q.empty()) {
    std::pair<int, int> p = q.front();
    q.pop();
    int t = ma[p.first][p.second] + 1;

    if (s[p.first][p.second] == -1) {
      std::cout << t - 1 << '\n';
      return 0;
    }

    for (int i = 1; i <= 4; i++) {
      int x = p.first + dx[i];
      int y = p.second + dy[i];

      if ((x >= 0) && (y >= 0) && ((t < s[x][y]) || (s[x][y] == -1)) && (!vis[x][y])) {
        vis[x][y] = 1;
        q.push(std::make_pair(x, y));
        ma[x][y] = t;
      }
    }
  }

  std::cout << -1;
}