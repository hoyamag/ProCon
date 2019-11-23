#include <bits/stdc++.h>
#define REP(i, a, n) for (long long i = (a); i < (long long)(n); ++i)
#define REPC(i, a, n) for (long long i = (a); i <= (long long)(n); ++i)
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
template <typename T>
ostream &operator<<(ostream &os, set<T> &s) {
  os << "{";
  for (auto p : s) os << p << ",";
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
#include <iostream>
// http://drken1215.hatenablog.com/entry/2018/06/08/210000
using namespace std;

const int MAX = 1e6+1;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
  int X, Y;
  cin >> X >> Y;
  int a = (2 * X - Y) / 3;
  int b = X - 2 * a;
  if ((2 * X - Y )% 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  COMinit();
  cout<<COM(a+b,a)<<endl;

  return 0;
}
