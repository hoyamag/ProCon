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
  int n, x;
  cin >> n >> x;
  VEC<pair<int, int>> a(n);
  REP(i, 0, n) cin >> a[i].first >> a[i].second;
  sort(ALL(a), [](pair<int, int> a, pair<int, int> b) -> bool {
    return a.second < b.second;
  });
  DUMP(a);
  reverse(ALL(a));
  int index = 0;
  DUMP(a);
  REP(i, 0, x) {
    if (a[index].first < 100)
      ++a[index].first;
    else {
      ++index;
      --i;
    }
  }

  LL sum = 0;
  REP(i, 0, n) { sum += a[i].first * a[i].second; }
  DUMP(a);
  cout << sum << endl;

  return 0;
}
