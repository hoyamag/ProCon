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
  VEC<LL> A(X + 1, -10000), B(Y + 1, -10000), C(Z + 1, -10000);
  REP(i, 0, X) cin >> A[i];
  REP(i, 0, Y) cin >> B[i];
  REP(i, 0, Z) cin >> C[i];
  sort(ALL(A), greater<LL>());
  sort(ALL(B), greater<LL>());
  sort(ALL(C), greater<LL>());
  VEC<LL> a(X - 1, 0), b(Y - 1, 0), c(Z - 1, 0);
  REP(i, 1, X) a[i - 1] = A[i] - A[0];
  REP(i, 1, Y) b[i - 1] = B[i] - B[0];
  REP(i, 1, Z) c[i - 1] = C[i] - C[0];
  int fa, fb, fc;
  fa = fb = fc = 0;
  priority_queue<LL> sums;
  DUMP("a, ", a);
  DUMP("b, ", b);
  DUMP("c, ", c);
  while (sums.size() < K) {
    // while(fa<X-1||fb<Y-1||fc<Z-1){
    DUMP("sums size, ", sums.size());
    VEC<LL> T;
    DUMP("fa, fb, fc, ", fa, fb, fc);
    if (fa < X - 1) T.push_back(a[fa]);
    if (fb < Y - 1) T.push_back(b[fb]);
    if (fc < Z - 1) T.push_back(c[fc]);

    sort(ALL(T));
    LL ma = T[T.size() - 1];
    DUMP("T", T);

    auto f = [&](LL ma, int s1, int s2, VEC<LL> &v1, VEC<LL> &v2) {
      REPC(i, 0, s1) {
        REPC(j, 0, s2) {
          DUMP("in f", ma + v1[i] + v2[j], ma, v1[i], v2[j]);
          sums.push(ma + v1[i] + v2[j]);
        }
      }
    };
    if (ma == a[fa] && fa < X) {
      fa++;
      DUMP("next fa, fb, fc, ", fa, fb, fc);
      f(A[fa], fb, fc, B, C);
    } else if (ma == b[fb] && fb < Y) {
      fb++;
      DUMP("next fa, fb, fc, ", fa, fb, fc);
      f(B[fb], fa, fc, A, C);
    } else if (ma == c[fc] && fc < Z) {
      fc++;
      DUMP("next fa, fb, fc, ", fa, fb, fc);
      f(C[fc], fa, fb, A, B);
    } else
      break;
  }
  //   REP(i, 0, K) {
  while (sums.empty() == false) {
    LL t = sums.top();
    sums.pop();
    cout << t << endl;
  }

  return 0;
}
