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
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  VEC<int> csA(N, 0);
  csA[0] = S[0] == 'A' ? 1 : 0;
  REP(i, 1, N) {
    csA[i] = csA[i - 1];
    if (S[i] == 'A') csA[i]++;
  }
  VEC<int> csAC(N, 0);
  // REP(i, 1, N) {
  //   csAC[i] = csAC[i - 1];
  //   if (S[i] == 'C') csAC[i] += csA[i - 1];
  // }
  REP(i, 1, N) {
    csAC[i] = csAC[i - 1];
    if (S[i - 1] == 'A' && S[i] == 'C') csAC[i]++;
  }
  DUMP(csA);
  DUMP(csAC);
  REP(i, 0, Q) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int ans = 0;
    if (S[l] == 'C' && S[l - 1] == 'A') --ans;
    ans += csAC[r] - (l - 1 >= 0 ? csAC[l - 1] : 0);
    cout << ans<<endl;
  }

  return 0;
}
