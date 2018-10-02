#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using LL = long long;
using ULL = unsigned long long;
using namespace std;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  int n;
  std::cin >> n;
  VEC<int> v(n);
  std::map<int, int> even, odd;
  REP(i, 0, n) {
    std::cin >> v[i];
    if (i % 2 == 0) {
      even[v[i]]++;
    } else {
      odd[v[i]]++;
    }
  }

  VEC<pair<int, int>> e(even.size()), o(odd.size());
  int i = 0;
  for (auto c : even) {
    e[i] = make_pair(c.second, c.first);
    ++i;
  }
  i = 0;
  for (auto c : odd) {
    o[i] = make_pair(c.second, c.first);
    ++i;
  }
  sort(ALL(e));
  reverse(ALL(e));
  sort(ALL(o));
  reverse(ALL(o));

  if (e[0].second == o[0].second) {
    int e1 = e[0].first;
    int e2 = (e.size() > 1 ? e[1].first : 0);
    int o1 = o[0].first;
    int o2 = (o.size() > 1 ? o[1].first : 0);
    std::cout << min(n - e1 - o2, n - e2 - o1) << endl;

  } else {
    std::cout << n - e[0].first - o[0].first << std::endl;
  }

  return 0;
}
