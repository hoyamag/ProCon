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
LL N, K;
VEC<LL> A;
LL answer(LL x) {
  LL sum = 0;
  REP(i, 0, N) {
    sum += (x xor A[i]);
    // DUMP(sum, x, A[i], x xor A[i]);
  }
  return sum;
}
/* test case
3 2
2 0 0

this: 5
true: 5
my previous wrong sub(but AC): 4
*/
int main() {
  cin >> N >> K;
  A = VEC<LL>(N);
  REP(i, 0, N) cin >> A[i];
  LL ma = pow(2, (LL)log2(K+1));
  DUMP(ma);
  LL x = 0;
  LL ans = 0;
  for (LL digit = ma; digit > 0; digit >>= 1) {
    if (((K + 1) & digit) == 0) continue;
    x = K + 1 - digit;
    for (LL i = (digit >> 1); i > 0; i >>= 1) {
      if ((x & i) > 0) x -= i;
    }

    for (LL bit = (digit >> 1); bit > 0; bit >>= 1) {
      // DUMP("bit: ", bit);
      LL cnt = 0;
      REP(i, 0, N) {
        // if on
        if ((bit & A[i]) > 0) {
          ++cnt;
        }
      }
      // DUMP("cnt: ", cnt);
      if (cnt < (double)N / 2) x += bit;
    }
    ans = max(ans, answer(x));
  }

  cout << ans << endl;

  return 0;
}
