#include <algorithm>
#include <bitset>
#include <cstdio>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repc(i, a, n) for (int i = (a); i <= (int)(n); i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init)                                              \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
#define DBG(str) cerr << (str) << endl;
bool isPrime(int n) {
  // returns whether n is prime number or not
  // n should be in range [0, lim].
  // to see detail, search "Sieve of Eratosthenes"
  static int lim = 1e5;
  static bool done = false;
  static vector<bool> isp(lim + 1, 1);
  if (!done) {
    isp[0] = isp[1] = false;
    for (int i = 2; i <= lim; i++) {
      if (isp[i]) {
        for (int j = i + i; j <= lim; j += i) {
          isp[j] = false;
        }
      }
    }
    done = true;
  }
  return isp[n];
}

int main() {
  int n;
  cin >> n;
  ll sum = 0;

  vector<int> p(n, 0);
  int i = 0;
  int index = 0;
  while (1) {
    if (isPrime(i) && i % 5 == 1) {
      p[index] = i;
      sum += i;
      index++;
    }
    i++;
    if (index == n)
      break;
  }

  rep(i, 0, n) cout << p[i] << " ";

  return 0;
}
