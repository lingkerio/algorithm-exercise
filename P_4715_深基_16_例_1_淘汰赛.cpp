#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n{};
  cin >> n;
  vector<std::pair<int, int>> arr = vector<std::pair<int, int>>((1 << (n + 1)) - 1);
  for (size_t i = (1 << n) - 1; i < arr.size(); i++) {
    cin >> arr[i].first;
    arr[i].second = i - (1 << n) + 2;
  }

  for (size_t i = (1 << (n - 1)) - 1; i > 0; i = i / 2) {
    for (size_t j = i; j < 2 * i + 1; j += 1) {
      if (arr[j * 2 + 1].first > arr[j * 2 + 2].first) {
        arr[j] = arr[j * 2 + 1];
      } else {
        arr[j] = arr[j * 2 + 2];
      }
    }
  }

  if (arr[1].first > arr[2].first) {
    cout << arr[2].second;
  } else {
    cout << arr[1].second;
  }
}