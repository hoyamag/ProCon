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

int N;
int dfs(string &S, int st) {
//   DUMP("st ", st);
  //   if (st < N && st+1>=N) return 1;
  if (st >= N) return 0;

  if (S[st] != S[st + 1]) {
    int l = dfs(S, st + 1) + 1;
    // DUMP("  ", l);
    return l;
  }
  if (st + 2 < N) {
    int l = dfs(S, st + 3) + 2;
    // DUMP("  ", l);
    return l;
  }
  return -(1 << 30);
}
int main() {
  string S;
  cin >> S;
  N = S.length();
  int ans = dfs(S, 0) ;
//   DUMP(ans);
  if (N >= 2) {
    ans = max(ans, dfs(S, 2) + 1);
  }
  cout << ans << endl;

  return 0;
}
