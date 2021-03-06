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

int main() {
  int D, G;
  cin >> D >> G;
  VEC<int> P(D), C(D);
  REP(i, 0, D) cin >> P[i] >> C[i];
  VEC<LL> sum(D, 0);
  REP(i, 0, D) {
    REP(j, 0, P[i]) sum[i] += (i + 1) * 100;
    sum[i] += C[i];
  }
  int lim = 1 << (D + 1);
  int ans = INT32_MAX;
  REP(bit, 0, lim) {
    LL point = 0;
    VEC<bool> used(D, 0);
    int cnt = 0;
    REP(i, 0, D) {
      if (bit & (1 << i)) {
        point += sum[i];
        cnt += P[i];
        used[i] = 1;
      }
    }
    for (int i = D - 1; i >= 0; --i) {
      if (used[i]) continue;
      for (int a = 0; a < P[i] && point < G; ++a) {
        ++cnt;
        point += (i + 1) * 100;
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}
