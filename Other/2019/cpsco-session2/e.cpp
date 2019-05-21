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

struct edge {
  int u, v, h;
};
int main() {
  int N;
  cin >> N;
  VEC<edge> E(N);
  REP(i, 0, N) {
    E[i].u = i + 1;
    cin >> E[i].v >> E[i].h;
  }
  queue<int> q;
  VEC<int> used(N, 0);
  VEC<int>H(N,0);
  q.push(0);
  int index=0;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    used[p] = 1;
    
    REP(i, 0, N) {
      int t = E[i].u;
      if (p == t && used[t] == false) {
        q.push(t);
      }
      t = E[i].v;
      if (p == t && used[t] == false) {
        q.push(t);
      }
    }
  }

  return 0;
}