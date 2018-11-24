
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
  int n, m;
  cin >> n >> m;
  VEC<pair<LL, int>> p(m);

  REP(i, 0, m) {
    cin >> p[i].second >> p[i].first;
    --p[i].second;
  }
  VEC<pair<LL, int>> orig=p;
  sort(ALL(p));
  VEC<VEC<LL>> city(n, VEC<LL>());
  VEC<map<LL, int>> index(n);
  REP(i, 0, m) {
    city[p[i].second].push_back(p[i].first);
    index[p[i].second][p[i].first] = city[p[i].second].size();
  }
  REP(i,0,m){
      int pre = orig[i].second;
      int year = orig[i].first;
      int num = index[pre][year];
      printf("%06d%06d\n", pre+1, num);
      
  }

  return 0;
}
