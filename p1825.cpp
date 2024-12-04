#include <bits/stdc++.h>
using namespace std;

int const N = 310;

char s[N][N];
bool vis[N][N];

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sx;
int sy;

struct point {
  int x;
  int y;
  int t;
};

queue<point> c;

void go(int& x, int& y) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == s[x][y] && ((i != x) || (j != y))) {
        x = i;
        y = j;
        return;
      }
    }
  }
}

int main() {
  cin >> n >> m;

  string str;

  for (int i = 1; i <= n; i++) {
    cin >> str;

    for (int j = 1; j <= m; j++) {
      s[i][j] = str[j - 1];
      if (s[i][j] == '@') {
        sx = i;
        sy = j;
      }
    }
  }

  c.push({sx, sy, 0});

  while (!c.empty()) {
    point f = c.front();
    c.pop();
    vis[f.x][f.y] = true;

    if (s[f.x][f.y] == '=') {
      cout << f.t;
      return 0;
    }

    if (s[f.x][f.y] <= 'Z' && s[f.x][f.y] >= 'A') {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (s[i][j] == s[f.x][f.y] && ((i != f.x) || (j != f.y))) {
            f.x = i;
            f.y = j;
            goto Exit;
          }
        }
      }
      Exit:;
    }

    for (int i = 0; i < 4; i++) {
      int u = f.x + dx[i];
      int v = f.y + dy[i];

      if (u < 1 || u > n || v < 1 || v > m || vis[u][v] || s[u][v] == '#') {
        continue;
      }
      vis[u][v] = true;
      c.push({u, v, f.t + 1});
    }
  }
}