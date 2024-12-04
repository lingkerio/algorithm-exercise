#include <string>

#include <bits/stdc++.h>
using namespace std;

void solve(string ino, string post) {
  if (ino.length() == 0) {
    return;
  }

  char root = post[post.length() - 1];
  int pos   = ino.find(root);
  cout << root;
  solve(ino.substr(0, pos), post.substr(0, pos));
  solve(ino.substr(pos + 1), post.substr(pos, post.length() - pos - 1));
}

int main() {
  string ino, post;

  cin >> ino >> post;

  solve(ino, post);
}