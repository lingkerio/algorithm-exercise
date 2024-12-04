#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int const N = 3100;
int len[20], m, n, pos[20], h[20];
char a[N][N];

int read() {
  int sum = 0, fu = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') {
      fu = -1;
    }
    ch = getchar();
  }
  while (isdigit(ch)) {
    sum = (sum << 1) + (sum << 3) + (ch ^ 48);
    ch  = getchar();
  }
  return sum * fu;
}

void prepare() {
  int sum = 1;
  len[1]  = 1;
  pos[1]  = 1;
  FOR(i, 2, m) {
    len[i]  = sum + i - 1;
    sum    += len[i];
    pos[i]  = len[i] + 1;
  }
  h[m] = 1;
  for (int i = m - 1; i; i--) {
    h[i] = h[i + 1] + len[i] + 1;
  }
  memset(a, ' ', sizeof(a));
}

void draw(int x, int y, int depth) {
  a[x][y] = 'o';
  if (depth == 1) {
    return;
  }
  int lx = x + 1, ly = y - 1, rx = x + 1, ry = y + 1;
  FOR(i, 1, len[depth - 1]) {
    a[lx][ly] = '/';
    a[rx][ry] = '\\';
    lx = lx + 1, ly = ly - 1, rx = rx + 1, ry = ry + 1;
  }
  draw(lx, ly, depth - 1);
  draw(rx, ry, depth - 1);
}

void destroy(int x, int y) {
  a[x][y] = ' ';
  if (a[x - 1][y - 1] == '\\') {
    destroy(x - 1, y - 1);
  }
  if (a[x - 1][y + 1] == '/') {
    destroy(x - 1, y + 1);
  }
  if (a[x + 1][y - 1] == '/' || a[x + 1][y - 1] == 'o') {
    destroy(x + 1, y - 1);
  }
  if (a[x + 1][y + 1] == '\\' || a[x + 1][y + 1] == 'o') {
    destroy(x + 1, y + 1);
  }
}

void print() {
  int height = h[1];
  int width  = 6 * (1 << (m - 1));
  FOR(i, 1, height) {
    FOR(j, 1, width) printf("%c", a[i][j]);
    printf("\n");
  }
}

int main() {
  m = read();
  n = read();
  prepare();
  draw(1, pos[m], m);
  while (n--) {
    int i = read(), j = read();
    if (i > 10) {
      continue;
    }
    int x = h[m + 1 - i], y;
    if (i == m) {
      if (j & 1) {
        y = pos[1] + j / 2 * 6;
      } else {
        y = pos[1] + j / 2 * 6 - 2;
      }
    } else {
      y = pos[m + 1 - i] + (j - 1) * (2 * len[m + 1 - i] + 2);
    }
    destroy(x, y);
  }
  print();
  return 0;
}
