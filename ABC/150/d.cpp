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
long long gcd(long long a, long long b) { /* the greatest common divisor*/
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { /*the least common multiple*/
  return (a / gcd(a, b)) * b;
}

int main() {
  // REP(x, 0, 1000) {
  //   printf("%5d %5d %5d %5d\n", x,14*x+7, 22*x+11, 40*x+20);
  //   if (x - 7 >= 0 && (x - 7) % 14 == 0) {
  //     if (x - 11 >= 0 && (x - 11) % 22 == 0) {
  //       if (x - 20 >= 0 && (x - 20) % 40 == 0) {
  //         cout <<"Found"<< x << endl;
  //       }
  //     }
  //   }
  // }
  LL N, M;
  cin >> N >> M;
  VEC<LL> A(N);
  REP(i, 0, N) cin >> A[i];
  LL lcmv = A[0];
  REP(i, 1, N) { lcmv = lcm(lcmv, A[i]); }
  // DUMP(lcmv);
  sort(ALL(A));

  VEC<LL> B(N);
  REP(i, 0, N) B[i] = A[i] / 2;
  sort(ALL(B));

  LL ma = B[N - 1];
  LL mi = B[0];
  LL lim = ma + lcmv + 1000;
  REP(i, 0, N-1) {
    if (B[i] % 2 != B[i + 1] % 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  while (mi != ma && ma <= lim && ma <= M) {
    // DUMP(B, mi, ma);
    REP(i, 0, N) {
      if (B[i] < ma) B[i] += (ma - B[i]) / A[i] * A[i];
    }

    mi = LLONG_MAX;
    ma = 0;
    REP(i, 0, N) {
      ma = max(ma, B[i]);
      mi = min(mi, B[i]);
    }
    if (mi != ma) {
      B[N - 1] += A[N - 1];
      ma = max(ma, B[N - 1]);
    }
  }
  if (mi != ma) {
    cout << 0 << endl;
    return 0;
  }
  LL first = B[0];
  // DUMP(B);
  // DUMP("first", first);
  LL cnt = (M - first) / lcmv + 1;
  cout << cnt << endl;

  return 0;
}
