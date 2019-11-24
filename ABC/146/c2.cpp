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
ULL A, B, X;
ULL keta(ULL n) {
  ULL cnt = 0;
  while (n > 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}
ULL f(ULL n) { return A * n + B * keta(n); }

int main() {
  cin >> A >> B >> X;
  //   cerr << X << endl;
  //   REP(i, 254309, 254309 + 250) {
  //     cerr << i << " " << f(i) << " " << (f(i) <= X) << endl;
  //   }
  const ULL lim = 1e9;
  ULL low = 0, high = lim + 1;
  ULL mid = 0;
  while (high - low > 1) {
    mid = (high + low) / 2;
    ULL v = f(mid);
    // DUMP(low, mid, high, "v ", v);
    if (v <= X) {
      low = mid;
    } else {
      high = mid;
    }
  }
  //   DUMP(low, mid, high);
  //   DUMP(f(low), f(low)<=X);
  //   cerr << low << endl;
  cout << low << endl;

  return 0;
}
