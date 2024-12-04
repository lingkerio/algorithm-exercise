#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
 private:
  vector<int> parent, rank;

 public:
  UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) {
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
};

int main() {
  int n{};
  int m{};
  int p{};

  cin >> n >> m >> p;
  auto uf = UnionFind(n+1);
  int m1, m2;
  for (size_t i = 0; i < m; i++) {
    cin >> m1 >> m2;
    uf.unite(m1, m2);
  }

  int p1, p2;
  for (size_t i = 0; i < p; i++) {
    cin >> p1 >> p2;
    if (uf.find(p1) == uf.find(p2)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}