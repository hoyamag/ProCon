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

const LL NMAX = 1e5;
VEC<list<int>> g(NMAX + 1);
VEC<set<int>> child(NMAX);
LL n;
LL m;
VEC<int> a, b;
set<int> add(set<int> a, set<int> b) {
  set<int> c;
  for (auto v : a) {
    c.insert(v);
  }
  for (auto v : b) {
    c.insert(v);
  }
  return c;
}
VEC<bool> sed(NMAX, 0);
void dfs(int node) {
  if (sed[node]) {
    for (auto v : g[node]) {
      child[node] = add(child[node], child[v]);
    }
  }
  sed[node] = 1;

  for (auto v : g[node]) {
    dfs(v);
    child[node] = add(child[node], child[v]);
  }
}
VEC<int> ans(NMAX, -1);
void makeans(int node) {
  if (sed[node]) return;
  sed[node] = 1;
  for (auto v : g[node]) {
    ans[v] = node+1;
    makeans(v);
  }
}
int main() {
  cin >> n >> m;
  a = VEC<int>(n - 1 + m);
  b = VEC<int>(n - 1 + m);
  REP(i, 0, n - 1 + m) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    g[a[i]].push_back(b[i]);
    child[a[i]].insert(b[i]);
  }
  // DUMP(93);
  REP(i, 0, n) { dfs(i); }
  int root = -1;
  REP(i, 0, n) {
    if (child[i].size() == n-1) {
      root = i;
    }
  }
  // DUMP(101, root);
  // REP(i,0,n){
  //   cerr<<"i="<<i<<":";
  //   for(auto v:child[i]){
  //     cerr<<v<<" ";
  //   }
  //   cerr<<endl;
  // }
  sed = VEC<bool>(n, 0);
  ans[root] = 0;
  makeans(root);
  // DUMP(105);
  REP(i, 0, n) { cout << ans[i] << endl; }

  return 0;
}
