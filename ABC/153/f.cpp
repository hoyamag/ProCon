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

//BITを考えたけど、尺取りもいけたよう
// imosという説もあった(by TL)(使った場所にマイナスを置くらしい)
// 既視感: ABC063d Widespread https://atcoder.jp/contests/abc063/tasks/arc075_b
int main() {
  LL N, D, A;
  cin >> N >> D >> A;
  VEC<pair<LL, LL>> M(N);
  REP(i, 0, N) {
    cin >> M[i].first >> M[i].second;
    M[i].second = (M[i].second + A - 1) / A;
  }

  sort(ALL(M));
  LL cnt = 0;
  LL i = 0;
  while (i < N) {
    int x = M[i].first;
    int nx = x + 2 * D;
    auto ub = upper_bound(ALL(M), make_pair((LL)nx, (LL)0));
    int ni = distance(M.begin(), ub);
    LL ma = 0;
    REP(j, i, ni) { ma = max(ma, M[j].second); }
    cnt += ma;

    DUMP("i,x,ni,nx,ma,cnt", i, x, ni, nx, ma, cnt);

    i = ni;
  }
  cout << cnt << endl;

  return 0;
}
