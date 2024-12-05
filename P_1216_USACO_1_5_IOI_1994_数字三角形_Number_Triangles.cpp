#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[1001][1001];

int main() {
  int n{};
  cin >> n;

  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  for (size_t i = 2; i <= n; i++) {
    for (size_t j = 1; j <= i; j++) {
      if (j == 1) {
        arr[i][j] += arr[i-1][j];
      } else if (j == i) {
        arr[i][j] += arr[i-1][j-1];
      } else {
        arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
      }
    }
  }

  sort(arr[n]+1, arr[n] + n + 1);

  cout << arr[n][n];
}