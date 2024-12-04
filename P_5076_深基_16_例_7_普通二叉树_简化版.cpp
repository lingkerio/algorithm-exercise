#include <iostream>
#include <set>
using namespace std;

set<int> bst;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int op, x;
    cin >> op >> x;

    if (op == 1) {
      auto it  = bst.lower_bound(x);
      int rank = distance(bst.begin(), it) + 1;
      cout << rank << endl;

    } else if (op == 2) {
      auto it = bst.begin();
      advance(it, x - 1);
      cout << *it << endl;

    } else if (op == 3) {
      auto it = bst.lower_bound(x);
      if (it == bst.begin()) {
        cout << -2147483647 << endl;
      } else {
        --it;
        cout << *it << endl;
      }

    } else if (op == 4) {
      auto it = bst.upper_bound(x);
      if (it == bst.end()) {
        cout << 2147483647 << endl;
      } else {
        cout << *it << endl;
      }

    } else if (op == 5) {
      bst.insert(x);
    }
  }

  return 0;
}
