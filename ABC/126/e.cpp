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
const int MAX_N = 1e5;
list<int> G[MAX_N + 1];
VEC<bool> used;
int unused;
VEC<bool> black;
void dfs(int node) {
  if (used[node]) return;
  // DUMP(node, dist);
  used[node] = 1;
  unused--;

  for (auto v : G[node]) {
    dfs(v);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  REP(i, 0, M) {
    int a, b;
    LL c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  used = VEC<bool>(N, 0);
  int cnt = 0;
  unused = N;
  REP(i, 0, N) {
    // DUMP(unused);
    int prev = unused;
    dfs(i);
    if (unused != prev) cnt++;
    if (unused == 0) break;
  }

  cout << cnt << endl;

  return 0;
}
