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

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char left = s[0];
  char right = s[n - 1];
  LL l = 0;
  LL r = 0;
  REP(i, 0, n) {
    if (s[i] == left)
      ++l;
    else
      break;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == right)
      ++r;
    else
      break;
  }
  LL ans = 0;
  LL M = 998244353;
  ans = ((l + r + 1) % M);
  if (left == right) {
    ans = (ans + (l * r) % M) % M;
  }
  cout<<ans<<'\n';

  return 0;
}
