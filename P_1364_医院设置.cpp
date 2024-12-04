#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n{};

int main() {
  cin >> n;
  auto pop   = vector<int>(n);
  auto graph = vector<vector<int>>(n, vector<int>(n, 1000000));

  for (size_t i = 0; i < n; i++) {
    graph[i][i] = 0;
    int l, r;
    cin >> pop[i] >> l >> r;
    if (l != 0) {
      graph[i][l-1] = graph[l-1][i] = 1;
    }
    if (r != 0) {
      graph[i][r-1] = graph[r-1][i] = 1;
    }
  }

  for (size_t k = 0; k < n; k++) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  auto Min = INT_MAX;
  for (size_t i = 0; i < n; i++) {
    int total = 0;
    for (size_t j = 0; j < n; j++) {
      total += pop[j] * graph[i][j];
    }

    Min = min(Min, total);
  }

  cout << Min;
}