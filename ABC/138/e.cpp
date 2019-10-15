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

VEC<VEC<int>> pos('z' - 'a' + 1);
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S, T;
  cin >> S >> T;
  REP(i, 0, S.length()) { pos[S[i] - 'a'].reserve(1e5); }
  REP(i, 0, S.length()) { pos[S[i] - 'a'].push_back(i); }
  LL loopnum = 0;
  int prevpos = -1;
  // REP(i, 'a', 'z' + 1) { DUMP((char)i, pos[i - 'a']); }
  REP(i, 0, T.length()) {
    if (pos[T[i] - 'a'].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  REP(i, 0, T.length()) {
    auto& poslist = pos[T[i] - 'a'];
    // DUMP(poslist);
    if (prevpos >= poslist[poslist.size() - 1]) {
      // DUMP("prevpos>max");
      loopnum++;
      prevpos = poslist[0];
      continue;
    }
    int newpos = *upper_bound(ALL(poslist), prevpos);
    // DUMP("prev, new:", prevpos, newpos);
    prevpos = newpos;
  }
  // DUMP("loopnum:", loopnum);
  LL ans = loopnum * S.length() + prevpos + 1;
  printf("%lld\n", ans);

  return 0;
}
