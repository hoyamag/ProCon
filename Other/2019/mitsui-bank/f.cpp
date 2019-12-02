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

int main() {
  LL T1, T2;
  LL A1, A2;
  LL B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  if (T1 * A1 + T2 * A2 == T1 * B1 + T2 * B2) {
    cout << "infinity" << endl;
    return 0;
  }
  LL da1 = 0, da2 = 0;
  LL db1 = 0, db2 = 0;
  int cnt = 0;
  while (1) {
    da1 = da2;
    db1 = db2;
    da1 += T1 * A1;
    db1 += T1 * B1;

    da2 = da1;
    db2 = db1;
    da2 += T2 * A2;
    db2 += T2 * B2;
    DUMP(da1, da2, db1, db2, cnt);
    if ((da1 <= db1 && da2 >= db2) || (da1 >= db1 && da2 <= db2)) {
      cnt++;
    } else
      break;

    da2 -= min(da2, db2);
    db2 -= min(da2, db2);
  }

  return 0;
}
