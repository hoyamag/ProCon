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
ULL digit_sum(ULL N) {
  ULL sum = 0;
  while (N > 0) {
    sum += N % 10;
    N /= 10;
  }
  return sum;
}

int main() {
  // cerr << log10(20) << endl;
  ULL N;
  cin >> N;
  ULL dsum = digit_sum(N);
  ULL dsum2 = dsum;
  ULL cand = dsum % 9;
  dsum -= cand;

  while (dsum > 0) {
    cand *= 10;
    cand += 9;
    dsum -= 9;
  }
  LL ans = 0;
  if (N != cand) {
    ans = cand;
  } else {
    dsum = dsum2;
    ULL w = max(1LL, (LL)pow(10, (int)log10(cand) - 1));
    while (N==cand||digit_sum(cand) != dsum) {
      // DUMP(cand);
      cand += 9 * w;
    }
    ans = cand;
  }
  cout << ans << endl;

  return 0;
}
