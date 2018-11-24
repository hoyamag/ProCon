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
const LL M = 1e9 + 7;
const LL s = 10;
const LL lim = 200001;
LL modpow(LL n) {
  static vector<LL> a(lim, -1);
  if (a[n] != -1) return a[n];
  LL ans = 1;
  REP(i, 0, s) { ans = (ans * n) % M; }
  a[n] = ans;
  return ans;
}

int main() {
  LL n;
  cin >> n;
  LL ans = 0;
  for (LL pm = 1; pm <= n; ++pm) {
    LL pc = (modpow(pm) +M- modpow(pm - 1))%M;
    LL pq = modpow(n / pm);
    ans = (ans + (pc * pq) % M) % M;
  }
  cout << ans << endl;

  return 0;
}
