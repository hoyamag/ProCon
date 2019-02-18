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
int n;
VEC<list<int>> g;
VEC<LL> A;
VEC<pair<LL, LL>> stat;
LL ans = 0;

bool isValid(pair<LL, LL> a, pair<LL, LL> b) {
  LL num = a.first + b.first;
  LL sum = a.second + b.second;
  return num == 0 || sum < 0;
}
VEC<bool> visit;

pair<LL, LL> dfs(int node) {
  int cpu = A[node] < 0 ? 1 : 0;
  pair<LL, LL> ns = {cpu, A[node]};
  visit[node] = 1;

  list<pair<LL, LL>> child;
  DUMP("HI", node);
  for (auto v : g[node]) {
    if (visit[v]) continue;
    auto c = dfs(v);
    if (isValid(ns, c)) {
      child.push_back(c);
      ns.first += c.first;
      ns.second += c.second;
    } else {
      ++ans;
    }
  }
  return ns;
}

int main() {
  cin >> n;
  A = VEC<LL>(n);
  REP(i, 0, n) cin >> A[i];
  g = VEC<list<int>>(n);
  REP(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  stat = VEC<pair<LL, LL>>(n, {0, 0});
  visit = VEC<bool>(n, 0);
  DUMP("HI");
  LL answer=1e9+3;
  REP(i, 0, n) { dfs(i);answer=min(answer,ans); }
  cout << answer << endl;

  return 0;
}
