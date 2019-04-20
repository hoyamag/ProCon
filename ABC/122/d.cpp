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

const int lim = 100;
const LL M = 1e9 + 7;
VEC<LL> have(lim + 1, 0);
LL U(int n) {
  static VEC<LL> f(lim + 1, -1);
  f[0]=1;
  f[1]=4;
  if (f[n] != -1) {
    return f[n];
  }
  f[n] = (4 * U(n - 1)) % M;
  return f[n];
}
VEC<LL> no(lim + 1, 0);
int main() {
  int n;
  cin >> n;
  no[1] = 4;
  no[2] = 4 * 4;
  no[3] = 61;
  no[4] = 230;
  have[3] = 3;
  have[4] = 26;
  REP(i, 5, n+1) {
    have[i] = (have[i-1]+(no[i - 2] + no[i - 3] + 6) % M)%M;
    no[i] = (U(i) - have[i] + M) % M;
  }
  DUMP(have);
  DUMP(no);

  cout<<no[n]<<endl;

  return 0;
}
