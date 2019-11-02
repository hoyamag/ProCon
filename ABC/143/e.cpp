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
VEC<VEC<LL>> G;
VEC<VEC<pair<int, LL>>> dp;
VEC<bool> used;
int N, M, L;
const LL inf = 1e9 + 1;
// void dfs(int node, int fuel, int count) {
//   used[node]=true;
//   REP(i,0,N){
//     if(used[i]!=false){
//       int cost = G[node][i];
//       if(cost<=fuel){
//         dp[node][i]=min(dp[node][i], count);
//       }
//     }

//   }
// }
pair<int, LL> ft(pair<int, LL> from, LL cost) {
  if (from.second >= cost) {
    return make_pair(from.first, from.second - cost);
  }
  return make_pair(from.first + 1, L - cost);
}
void dijk(int s) {
  int v = -1;
  auto &d = dp[s];
  while (1) {
    REP(i, 0, N) {
      if (!used[i] && (v == -1 || d[i] < d[v])) v = i;
    }
    if (v != -1) break;
  }
  used[v] = true;
  REP(u, 0, N) { d[u] = min(d[u], ft(d[v], G[v][u])); }
}

int main() {
  cin >> N >> M >> L;
  VEC<LL> A(M), B(M), C(M);
  G = VEC<VEC<LL>>(N, VEC<LL>(N, inf));
  REP(i, 0, M) {
    cin >> A[i] >> B[i] >> C[i];
    if(C[i]<=L) G[A[i] - 1][B[i] - 1] = G[B[i] - 1][A[i] - 1] = C[i];
  }
  int Q;
  cin >> Q;
  VEC<int> S(Q), T(Q);
  REP(i, 0, Q) cin >> S[i] >> T[i];
  auto ini = make_pair(inf, 0LL);
  auto dp = VEC<VEC<pair<int, LL>>>(
      N + 1, VEC<pair<int, LL>>(N + 1, make_pair(inf, 0LL)));
  // dp = VEC<VEC<int>>(N, VEC<int>(N, inf));
  // REP(i, 0, N) { dp[i][i] = 0; }
  // REP(start, 0, N) {
  //   queue<int> edges;
  //   used = VEC<bool>(N, false);
  // }
  REP(i, 0, N) {
    used = VEC<bool>(0);
    dijk(i);
  }
  REP(i, 0, Q) { cout << dp[S[i]][T[i]].first << endl; }

  return 0;
}
