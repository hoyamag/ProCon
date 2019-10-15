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

VEC<list<int>> G;
VEC<int> Cnt;
VEC<LL> Ans;
VEC<bool> visited;
void dfs(int node, int weight) {
  visited[node] = true;
  weight += Cnt[node];
  Ans[node] = weight;

  for (auto v : G[node]) {
    if (!visited[v]) dfs(v, weight);
  }
}
int main() {
  int N, Q;
  cin >> N >> Q;
  G = VEC<list<int>>(N, list<int>());
  REP(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  VEC<pair<int, int>> P(Q);
  Cnt = VEC<int>(N, 0);
  REP(i, 0, Q) {
    cin >> P[i].first >> P[i].second;
    P[i].first--;
    Cnt[P[i].first] += P[i].second;
  }
  // DUMP(Cnt);
  Ans = VEC<LL>(N, 0);
  visited = VEC<bool>(N, 0);
  dfs(0, 0);
  REP(i, 0, N) { cout << Ans[i] << " "; }
  cout<<endl;

  return 0;
}
