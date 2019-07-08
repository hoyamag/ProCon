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
const int MAXN = 1e5;
VEC<int> G[MAXN + 1];

int main() {
  int N, M;
  cin >> N >> M;
  REP(i, 0, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
  }
  int S, T;
  S--;
  T--;
  cin >> S >> T;
  queue<pair<int, int>> q;
  q.push({S, 0});
  int count = 0;
  while (!q.empty()) {
    if (count >= 4 * N + 1) {
      cout << -1 << endl;
      return 0;
    }
    int cn = q.front().first;
    int ck = q.front().second;
    DUMP(cn, ck);
    count++;
    q.pop();
    if (cn == T && ck == 0) {
      cout << count/3 << endl;
      return 0;
    }
    REP(i, 0, G[cn].size()) { q.push({G[cn][i], (ck + 1) % 3}); }
  }
  cout<<-1<<endl;

  return 0;
}
