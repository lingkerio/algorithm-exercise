#include <iostream>
using namespace std;
int a[100001], b[100001], map[100001], f[100001];
int main() {
  int n{};
  cin >> n;

  for (size_t i = 1; i <= n; i++) {
    cin >> a[i];
    map[a[i]] = i;
  }

  for (size_t i = 1; i <= n; i++) {
    cin >> b[i];
    f[i] = 0x7f'ff'ff'ff;
  }
  int ans{1};
  f[1] = map[b[1]];

  for (size_t i = 1; i <= n; i++) {
    int l{1}, r{ans}, mid{};
    if (map[b[i]] > f[ans]) {
      f[ans + 1] = map[b[i]];
      ans++;
    } else {
      while (l < r) {
        mid = (l + r) / 2;
        if (f[mid] > map[b[i]]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      f[l] = map[b[i]];
    }
  }

  cout << ans;
}
