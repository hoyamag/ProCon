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
long long positive_mod(long long a, long long b) {
  /*mod演算。return value range [0,b-1]*/
  if (b < 0) assert(false);
  if (a < 0) {
    a += (LL)(ceil(((double)-a / b))) * b;
  }
  return a % b;
}

int main() {
  int n;
  cin >> n;
  VEC<LL> a(n), b(n);
  REP(i, 0, n) { cin >> a[i] >> b[i]; }
  LL sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    LL surplus = (a[i] + sum) % b[i];
    sum += (surplus == 0 ? 0 : b[i] - surplus);
    // DUMP(sum);
  }
  cout << sum << endl;

  return 0;
}
