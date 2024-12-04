#include <bits/stdc++.h>
using namespace std;

void solve(string ino, string pre) {
  if (ino.length() == 0) {
    return;
  }
  char root = pre[0];
  int pos   = ino.find(root);
  solve(ino.substr(0, pos), pre.substr(1, pos));
  solve(ino.substr(pos + 1), pre.substr(pos + 1));
  cout << root;
}

int main() {
  string ino, pre;
  cin >> ino >> pre;

  solve(ino, pre);
}