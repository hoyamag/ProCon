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

int main() {
  LL X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  VEC<LL> A(X+1, -10000), B(Y+1,-10000), C(Z+1,-10000);
  REP(i, 0, X) cin >> A[i];
  REP(i, 0, Y) cin >> B[i];
  REP(i, 0, Z) cin >> C[i];
  sort(ALL(A), greater<LL>());
  sort(ALL(B), greater<LL>());
  sort(ALL(C), greater<LL>());
  VEC<LL> a(X), b(Y), c(Z);
  REP(i, 0, X) a[i] = A[i] - A[0];
  REP(i, 0, Y) b[i] = B[i] - B[0];
  REP(i, 0, Z) c[i] = C[i] - C[0];
  int fa, fb, fc;
  fa = fb = fc = 1;
  priority_queue<LL> sums;
  sums.push(A[0] + B[0] + C[0]);
  DUMP(a);
  DUMP(b);
  DUMP(c);
  while (sums.size() < K) {
    DUMP(sums.size());
    VEC<LL> T;
    if(fa<X)T.push_back(a[fa]);
    if(fb<Y)T.push_back(b[fb]);
    if(fc<Z)T.push_back(c[fc]);
    sort(ALL(T));
    LL ma = T[T.size()-1];
    cerr<<ma<<","<<max({a[fa], b[fb], c[fc]})<<endl;
    DUMP("T", T);

    if (ma == a[fa] && fa<X)
      fa++;
    else if (ma == b[fb]&&fb<Y)
      fb++;
    else if (ma == c[fc]&&fc<Z)
      fc++;
    priority_queue<LL> newSums;
    DUMP(fa,fb,fc, "a[]]", a[fa], b[fb], c[fc],"ma", ma);
    while (sums.empty() ==false) {
      newSums.push(sums.top());
      newSums.push(sums.top() + ma);
      sums.pop();
    }
    sums = newSums;
  }
  REP(i,0,K){
    LL t = sums.top();
    sums.pop();
    cout<<t<<endl;
  }

  return 0;
}
