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

int main() {
  int N;
  cin >> N;
  VEC<int> A(N);
  REP(i, 0, N) cin >> A[i];

  VEC<LL> ans(N, 0);
  int lim = 30;
  REP(b, 0, lim) {
    VEC<int> zeroNum(N, 0), oneNum(N, 0);
    REP(i, 0, N) {
      if ((A[i] >> b) & 1) {
        oneNum[i]++;
      } else {
        zeroNum[i]++;
      }
    }
    REP(i, 1, N) {
      oneNum[i] += oneNum[i - 1];
      zeroNum[i] += zeroNum[i - 1];
    }
    // DUMP(b, oneNum, zeroNum);
    REP(k, 0, N) {
      int xk = oneNum[k] % 2 ? 1 : 0;
      LL pow2 = pow(2,b);
      if (xk == 0) {
        ans[k] += pow2*oneNum[k] ;
      } else {
        ans[k] += pow2*zeroNum[k] ;
      }
    }
    // DUMP(ans);
  }
  REP(i, 0, N) { cout << ans[i] << endl; }

  return 0;
}
