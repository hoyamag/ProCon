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
string L;
int N;
VEC<LL> dp;
/* calculate n^p mod M. O(log(p)) */ long long modpow(long long n, long long p,
                                                      long long M) {
  long long ans = 1;
  while (p > 0) {
    if (p & 1) ans = (ans * n) % M;
    n = (n * n) % M;
    p >>= 1;
  }
  return ans;
}
LL M = 1e9 + 7;

LL F(LL n, bool freeA, bool freeB) {
  static LL M = 1e9 + 7;
  if(n==1)return 1;
  LL k1 = modpow(3, n, M);
  if(freeA && freeB){
    return k1;
  }
  LL k2 = F(n - 1, 1, freeB);
  LL k3 = F(n - 1, freeA, 1);
  return ((k1 + k2) % M + k3) % M;
}
int main() {
  DUMP("Q)");
  // cerr<<pow(2,100000)<<endl;
  cin >> L;
  N = L.length();
  dp = VEC<LL>(N);
  cout<<F(N,0,0)<<endl;

  return 0;
}
