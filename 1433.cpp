#include <bits/stdc++.h>
using namespace std;

int n, cur;
double ans = DBL_MAX;

struct point {
  int x;
  int y;
  int vis;
};

point s[16];

double compute(point p1, point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void dfs(point np, double curlen, int count) {
  cur++;

  if (count == n) {
    ans = min(ans, curlen);
    return;
  }

  if (curlen > ans) return;
  for (int i = 1; i <= n; i++) {
    if (!s[i].vis) {
      s[i].vis = 1;
      dfs(s[i], curlen + compute(np, s[i]), count + 1);
      s[i].vis = 0;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].x >> s[i].y;
  }

  for (int i = 1; i <= n; i++) {
    s[i].vis = 1;
    dfs(s[i], compute(s[i], {0, 0, 0}), 1);
    s[i].vis = 0;
  }

  cout << fixed << setprecision(2) << ans << '\n';
}
