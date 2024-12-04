#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  auto prefix = string{};
  auto postfix = string{};
  cin >> prefix >> postfix;

  auto length = prefix.length();
  auto ans    = 0ll;
  
  for (size_t i = 0; i < length - 1; i++) {
    for (size_t j = 1; j < length; j++) {
      if (prefix[i] == postfix[j] && prefix[i + 1] == postfix[j - 1]) {
        ans++;
      }
    }
  }

  cout << (1 << ans);
}