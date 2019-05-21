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
bool isPrime(int n) {
  if (n <= 3) return 1;
  for (int i = 2; i * i <= n; i += 1) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
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
  int N;
  cin >> N;
  VEC<LL> A(N);
  REP(i, 0, N) { cin >> A[i]; }
  VEC<LL> Left(N), Right(N);
  Left[0] = A[0];
  Right[N - 1] = A[N - 1];
  REP(i, 1, N) {
    Left[i] = gcd(Left[i - 1], A[i]);
    Right[N - i - 1] = gcd(Right[N - i], A[N - i - 1]);
  }
  LL ans = 0;
  REP(i, 0, N) {
    LL l = i - 1 >= 0 ? Left[i - 1] : Right[i + 1];
    LL r = i + 1 < N ? Right[i + 1] : Left[i - 1];
    ans = max(ans, gcd(l, r));
  }
  cout<<ans<<endl;

  return 0;
}
