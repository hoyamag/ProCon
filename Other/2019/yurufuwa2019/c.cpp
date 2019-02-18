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

pair<int, int> kiyaku(int a, int b) {
  // a/b;
  int m = max(a, b);
  for (int i = m; i >= 2; --i) {
    if (a % i == 0 && b % i == 0) {
      a /= i;
      b /= i;
    }
  }
  return {a, b};
}
int main() {
  int N;
  cin >> N;
  VEC<int> S(N), T(N);
  REP(i, 0, N) cin >> S[i];
  REP(i, 0, N) cin >> T[i];
  // cerr << kiyaku(6, 10) << endl;
  // cerr << kiyaku(3, 10) << endl;
  REP(i, 0, N) {
    int a, b;
    tie(a, b) = kiyaku(S[i] - T[i], S[0]);
    cout<<a<<" "<<b<<endl;
  }

  return 0;
}
