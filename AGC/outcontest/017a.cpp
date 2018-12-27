#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail>
void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
std::vector<std::vector<long long>> combTableByPascalsTriangle(
    int n) { /*パスカルの三角形を利用した組合せの前計算。O(N^2)。 * arg... *
int n: 組合せ計算したい要素の個数。nCrで指定しうる最大のn *
return... *  vector<vector<long long>> c :
組合せ計算nCrの結果がc[n][r]に入っている。 */
  auto c = std::vector<std::vector<long long>>(
      n + 1, std::vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 or j == i) {
        c[i][j] = 1LL;
      } else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
      }
    }
  }
  return c;
}

int main() {
  int n, p;
  cin >> n >> p;
  VEC<int> b(n);
  int n0 = 0, n1 = 0;
  REP(i, 0, n) {
    int a;
    cin >> a;
    b[i] = a % 2;
    b[i] ? ++n1 : ++n0;
  }
  auto comb = combTableByPascalsTriangle(n);
  auto f = [&](int p) -> LL {
    LL ans = 0;
    for (int k = p; k <= n1; k += 2) {
      // ans += comb[n0][n - k] * comb[n1][k];
      ans += (LL)pow(2, n0) * comb[n1][k];
    }
    return ans;
  };
  LL ans = f(p);

  cout << ans << endl;

  return 0;
}
