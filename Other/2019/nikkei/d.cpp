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
  LL l, r;
  LL c;
};
ostream &operator<<(ostream &os, edge &a) {
  os << "(" << a.l << "," << a.r << "," << a.c << ")";
  return os;
}
bool edge_compare(edge &a, edge &b) {
  if (a.l == b.l) {
    if (a.r == b.r) {
      return a.c < b.c;
    } else {
      return a.r < b.r;
    }
  } else {
    return a.l < b.l;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  VEC<LL> L(M), R(M), C(M);
  VEC<edge> E(M);
  REP(i, 0, M) {
    cin >> L[i] >> R[i] >> C[i];
    L[i]--;
    R[i]--;
    E[i] = {L[i], R[i], C[i]};
  }
  sort(ALL(E), edge_compare);
  DUMP(E);
  VEC<LL> dp(N, 1e12);
  priority_queue<pair<LL, int>, VEC<pair<LL, int>>, greater<pair<LL, int>>>
      available_edges;

  int ave_index = 0;
  dp[0] = 0;
  REP(pos, 1, N) {
    DUMP(dp);
    while (E[ave_index].l <= pos-1 && ave_index < N) {
      auto aedge = E[ave_index];
      LL cost = dp[aedge.l] + aedge.c;
      LL limit = aedge.r;
      available_edges.push({cost, limit});
      dp[aedge.r] = min(cost, dp[aedge.r]);
      DUMP("ave in", aedge, cost, limit);
      ave_index++;
    }
    while (available_edges.top().second < pos) {
      DUMP("ave out", available_edges.top());
      available_edges.pop();
    }
    if (available_edges.empty() == false) {
      auto e = available_edges.top();
      dp[pos] = min(dp[pos], e.first);
    }
    DUMP(pos, dp[pos]);
  }
  cout << dp[N - 1] << endl;

  return 0;
}
