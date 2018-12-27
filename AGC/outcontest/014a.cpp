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
LL fac2(LL n) {
  LL cnt = 0;
  while (n % 2 == 0) {
    ++cnt;
    n /= 2;
  }
  return cnt;
}

int main() {
  LL A, B, C;
  cin >> A >> B >> C;
  if (A == B && B == C && C == A) {
    LL sum = A + B + C;
    cout << (sum % 2 == 0 ? -1 : 0) << endl;
    return 0;
  }
  int cnt = 0;
  while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
    int na = B / 2 + C / 2;
    int nb = A / 2 + C / 2;
    int nc = A / 2 + B / 2;
    A = na;
    B = nb;
    C = nc;
    ++cnt;
  }
  cout << cnt << endl;

  return 0;
}
