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
#define ull unsigned long long
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1n(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;

/*
        蟻本P190よりmax_flow。
        中身は理解してない。

*/
struct edge {
  LL to, cap, rev;
};
const int MAX_V = 4*1e5+3;
const LL INF = INT64_MAX;
vector<bool> used(MAX_V);
vector<edge> G[MAX_V];
void add_edge(LL from, LL to, LL cap) {
  G[from].push_back(edge({to, cap, (LL)G[to].size()}));
  G[to].push_back(edge({from, 0, (LL)G[from].size() - 1}));
}
LL dfs(LL v, LL t, LL f) {
  if (v == t) return f;
  used[v] = true;
  for (LL i = 0; i < G[v].size(); i++) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      LL d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }

  return 0;
}
LL max_flow(LL s, LL t) {
  LL flow = 0;
  for (;;) {
    rep(i, MAX_V) used[i] = 0;
    LL f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

int sample() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, n) cin >> c[i] >> d[i];
  int s = 2 * n;
  int t = 2 * n + 1;
  rep(i, n) {
    add_edge(s, i, 1);
    add_edge(n + i, t, 1);
  }

  rep(i, n) {
    rep(j, n) {
      if (a[i] < c[j] && b[i] < d[j]) {
        add_edge(i, j + n, 1);
      }
    }
  }
  cout << max_flow(s, t);

  return 0;
}

const LL LIM = 1e9;
int main() {
  int n;
  cin >> n;
  VEC<LL> a(n);
  REP(i, 0, n) cin >> a[i];
  sort(ALL(a));
  VEC<pair<LL, LL>> edge;
  for (LL nibeki = 1; nibeki <= 2 * LIM; nibeki *= 2) {
    auto iterator_begin = a.begin();
    REP(i, 0, n) {
      LL left = a[i];
      LL right = nibeki - a[i];
      if (right <= 0) {
        ++iterator_begin;
        continue;
      }
      auto next = iterator_begin+1;
      auto actual_p = lower_bound(next, a.end(), right);
      int j = distance(a.begin(), actual_p);
      LL actual = *actual_p;
      while (a[j] == right) {
        edge.push_back({i, j});
        //edge.push_back({j, i});
        ++j;
      }
      ++iterator_begin;
    }
  }
  // DUMP(a);
  // DUMP(edge);
  int m = edge.size();
  int start = MAX_V-1;
  int end = MAX_V-2;
  int left_end = end/2;
  REP(i,0,left_end){
    add_edge(start, i, 1);
    add_edge(left_end+i, end, 1);
  }

  REP(i,0,m){
    LL left = edge[i].first;
    LL right = edge[i].second;
    add_edge(left,right+left_end, 1);
  }
  cout<<max_flow(start,end)<<endl;
  

  return 0;
}
