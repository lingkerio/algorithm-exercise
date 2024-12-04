#include <iostream>
#include <queue>

int s[202];
int n, a, b;
int visit[202];
int taken[202];

int main() {
  std::cin >> n >> a >> b;

  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
  }

  std::queue<int> c{};

  c.push(a);
  visit[a] = 1;

  while (!c.empty()) {
    int cur = c.front();
    c.pop();

    if (cur - s[cur] >= 1 && !visit[cur - s[cur]]) {
      taken[cur - s[cur]] = taken[cur] + 1;
      visit[cur - s[cur]] = 1;
      c.push(cur - s[cur]);
    }

    if (cur + s[cur] <= n && !visit[cur + s[cur]]) {
      taken[cur + s[cur]] = taken[cur] + 1;
      visit[cur + s[cur]] = 1;
      c.push(cur + s[cur]);
    }
  }

  std::cout << (visit[b] ? taken[b] : -1);
}