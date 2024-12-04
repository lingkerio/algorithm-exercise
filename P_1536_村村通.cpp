#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
 private:
  vector<int> parent, rank;

 public:
  UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return false;
    }
    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    return true;
  }

  int countConnectedComponents(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      if (find(i) == i) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  while (true) {
    int n, m;
    cin >> n;
    if (n != 0) {
      cin >> m;
    } else {
      break;
    }

    if (n == 0 && m == 0) {
      break;
    }

    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      uf.unite(u, v);
    }

    int connectedComponents = uf.countConnectedComponents(n);
    cout << connectedComponents - 1 << endl;
  }

  return 0;
}
