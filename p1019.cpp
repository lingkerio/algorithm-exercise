#include <bits/stdc++.h>
using namespace std;
string str[20];
int use[20], length = 0, n;

int link(string s1, string s2) {
  for (int i = 1; i < min(s1.length(), s2.length()); i++) {
    int flag = 1;
    for (int j = 0; j < i; j++) {
      if (s1[s1.length() - i + j] != s2[j]) {
        flag = 0;
      }
    }
    if (flag) {
      return i;
    }
  }

  return 0;
}

void dfs(string s, int len) {
  length = max(length, len);

  for (int i = 0; i < n; i++) {
    if (use[i] >= 2) {
      continue;
    }

    int c = link(s, str[i]);

    if (c > 0) {
      use[i]++;
      dfs(str[i], len + str[i].length() - c);
      use[i]--;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    use[i] = 0, cin >> str[i];
  }
  dfs(' ' + str[n],
      1);
  cout << length;
}
