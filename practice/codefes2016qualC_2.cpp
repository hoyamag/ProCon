#include <bits/stdc++.h>
using namespace std;
int main() {
  int K, T;
  cin >> K >> T;
  int a = 0;
  int t;
  while (T > 0) {
    T--;
    cin >> t;
    a = a > t ? a : t;
  }
  cout << max(a - 1 - (K - a), 0);
  return 0;
}