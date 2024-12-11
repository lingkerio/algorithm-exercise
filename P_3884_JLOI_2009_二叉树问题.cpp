#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


vector<vector<int>> tree;
unordered_map<int, int> depth_map, parent_map;


pair<int, int> calculateDepthWidth(int root, int n) {
  queue<pair<int, int>> q;
  vector<int> visited(n + 1, false);
  vector<int> level_count(n, 0);
  int max_depth = 0;

  q.push({root, 0});
  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();
    if (visited[node]) {
      continue;
    }
    visited[node] = true;
    max_depth     = max(max_depth, depth);
    level_count[depth]++;
    for (int neighbor : tree[node]) {
      if (!visited[neighbor]) {
        q.push({neighbor, depth + 1});
      }
    }
  }

  int max_width = *max_element(level_count.begin(), level_count.end());
  return {max_depth + 1, max_width};
}

void dfsPaths(int node, int parent, int depth) {
  parent_map[node] = parent;
  depth_map[node]  = depth;
  for (int neighbor : tree[node]) {
    if (neighbor != parent) {
      dfsPaths(neighbor, node, depth + 1);
    }
  }
}

int findLCA(int u, int v) {
  unordered_map<int, bool> ancestors;
  while (u != -1) {
    ancestors[u] = true;
    u            = parent_map[u];
  }
  while (v != -1) {
    if (ancestors[v]) {
      return v;
    }
    v = parent_map[v];
  }
  return -1;
}

int main() {
  int n;
  cin >> n;

  tree.resize(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  int x, y;
  cin >> x >> y;


  dfsPaths(1, -1, 0);


  auto [depth, width] = calculateDepthWidth(1, n);


  int lca      = findLCA(x, y);
  int distance = (depth_map[x] - depth_map[lca]) * 2 + (depth_map[y] - depth_map[lca]);

  cout << depth << endl;
  cout << width << endl;
  cout << distance << endl;

  return 0;
}
