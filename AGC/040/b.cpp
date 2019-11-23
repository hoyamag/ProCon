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
bool second_lesser(pair<LL, LL> &a, pair<LL, LL> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return b.second > a.second;
}
LL calcPoint(pair<LL, LL> &a) { return a.second - a.first + 1; }

int main() {
  int N;
  cin >> N;
  VEC<pair<LL, LL>> UL(N), UR(N);
  REP(i, 0, N) {
    cin >> UL[i].first >> UL[i].second;
    UR[i] = UL[i];
  }
  sort(ALL(UL));
  sort(ALL(UR), second_lesser);
  DUMP(UL);
  DUMP(UR);

  LL point = 0;
  VEC<LL> lmax(N, 0);
  VEC<LL> rmin(N, 1e9 + 1);
  REP(i, 0, N) {
    auto q = UL[i];
    for (int j = N - 1; j >= 0; j--) {
      auto &t = UL[j];
      if (t.first <= q.first && q.second <= t.second) {
        continue;
      }
      lmax[i] = t.first;
      break;
    }

    REP(j, 0, N) {
      auto &t = UR[j];
      if (t.first <= q.first && q.second <= t.second) {
        continue;
      }
      rmin[i] = t.second;
      break;
    }
    LL pcand = rmin[i]-lmax[i]+1;
    DUMP(q, pcand, point, lmax[i], rmin[i]);
    point = max(point, pcand);
  }
  cout << point << endl;

  return 0;
}
