#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Floyd-Warshall Algorithm
void floydWarshall(int V, vector<vector<int>>& graph) {
  // 初始化距离矩阵
  vector<vector<int>> dist = graph;

  // Floyd-Warshall 主算法
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  // 输出结果
  cout << "Floyd-Warshall Result (Distance Matrix):\n";
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (dist[i][j] == INT_MAX) {
        cout << "INF ";
      } else {
        cout << dist[i][j] << " ";
      }
    }
    cout << endl;
  }
}

// Bellman-Ford Algorithm
void bellmanFord(int V, vector<vector<pair<int, int>>>& adj, int source) {
  vector<int> dist(V, INT_MAX);
  dist[source] = 0;

  // Bellman-Ford 主算法
  for (int i = 1; i < V; ++i) {
    for (int u = 0; u < V; ++u) {
      for (auto& edge : adj[u]) {
        int v = edge.first, weight = edge.second;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
        }
      }
    }
  }

  // 检查负环
  for (int u = 0; u < V; ++u) {
    for (auto& edge : adj[u]) {
      int v = edge.first, weight = edge.second;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        cout << "Graph contains negative weight cycle\n";
        return;
      }
    }
  }

  // 输出结果
  cout << "Bellman-Ford Result (Shortest Distances from Source):\n";
  for (int i = 0; i < V; ++i) {
    if (dist[i] == INT_MAX) {
      cout << "INF ";
    } else {
      cout << dist[i] << " ";
    }
  }
  cout << endl;
}

// SPFA Algorithm
void spfa(int V, vector<vector<pair<int, int>>>& adj, int source) {
  vector<int> dist(V, INT_MAX);
  vector<int> inQueue(V, false);
  dist[source] = 0;
  queue<int> q;
  q.push(source);
  inQueue[source] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inQueue[u] = false;

    for (auto& edge : adj[u]) {
      int v = edge.first, weight = edge.second;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        if (!inQueue[v]) {
          q.push(v);
          inQueue[v] = true;
        }
      }
    }
  }

  // 输出结果
  cout << "SPFA Result (Shortest Distances from Source):\n";
  for (int i = 0; i < V; ++i) {
    if (dist[i] == INT_MAX) {
      cout << "INF ";
    } else {
      cout << dist[i] << " ";
    }
  }
  cout << endl;
}

// Dijkstra Algorithm (Standard)
void dijkstra(int V, vector<vector<pair<int, int>>>& adj, int source) {
  vector<int> dist(V, INT_MAX);
  vector<int> visited(V, 0);
  dist[source] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, source});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) {
      continue;
    }

    visited[u] = 1;

    for (auto& edge : adj[u]) {
      int v = edge.first, weight = edge.second;
      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  // 输出结果
  cout << "Dijkstra Result (Shortest Distances from Source):\n";
  for (int i = 0; i < V; ++i) {
    if (dist[i] == INT_MAX) {
      cout << "INF ";
    } else {
      cout << dist[i] << " ";
    }
  }
  cout << endl;
}

// Unit Test
int main() {
  int V = 5;
  vector<vector<pair<int, int>>> adj(V);

  // Sample Graph for Testing (Directed graph with positive weights only for Dijkstra)
  adj[0].push_back({1, 4});
  adj[0].push_back({2, 1});
  adj[1].push_back({2, 2});
  adj[1].push_back({3, 5});
  adj[2].push_back({3, 1});
  adj[3].push_back({4, 3});

  // Test Floyd-Warshall Algorithm
  vector<vector<int>> graph = {{0, 4, 1, INT_MAX, INT_MAX},
                               {INT_MAX, 0, 2, 5, INT_MAX},
                               {INT_MAX, INT_MAX, 0, 1, INT_MAX},
                               {INT_MAX, INT_MAX, INT_MAX, 0, 3},
                               {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
  floydWarshall(V, graph);

  // Test Bellman-Ford Algorithm
  bellmanFord(V, adj, 0);

  // Test SPFA Algorithm
  spfa(V, adj, 0);

  // Test Dijkstra Algorithm (Standard) - Correct for graphs without negative weights
  dijkstra(V, adj, 0);

  return 0;
}
