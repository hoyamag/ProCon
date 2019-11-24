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
  int N;
  cin >> N;
  VEC<pair<int, int>> G(N);
  VEC<int> jisu(N, 0);
  int color_num = 0;
  REP(i, 0, N - 1) {
    cin >> G[i].first >> G[i].second;
    G[i].first--;
    G[i].second--;
    if (G[i].first > G[i].second) swap(G[i].first, G[i].second);
    jisu[G[i].first]++;
    jisu[G[i].second]++;
    color_num = max({color_num, jisu[G[i].first], jisu[G[i].second]});
  }
  cerr << endl;
  VEC<set<int>> available(N);
  REP(i, 0, N) {
    REP(j, 0, color_num) { available[i].insert(j + 1); }
  }

  cout << color_num << endl;
  REP(i, 0, N - 1) {
    int p = G[i].first;
    int q = G[i].second;
    // DUMP(available[p], available[q]);
    REP(c, 0, color_num) {
      if (available[p].count(c + 1) > 0 && available[q].count(c + 1) > 0) {
        cout << c + 1 << endl;
        available[p].erase(c + 1);
        available[q].erase(c + 1);
        break;
      }
    }
  }

  return 0;
}
