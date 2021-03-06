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

int main() {
  LL N, C, K;
  cin >> N >> C >> K;
  VEC<LL> T(N);
  REP(i, 0, N) cin >> T[i];
  sort(ALL(T));
  LL lim = T[0] + K;
  int num = 0;
  int pcnt = 0;
  int bcnt = 0;

  int i = 0;
  while (pcnt <= N && i<N) {
    // DUMP(i,pcnt,bcnt,lim);
    if (T[i] <= lim && num < C) {
      ++num;
      ++i;
    } else {
      pcnt += num;
      num = max(num - C, 0LL);
      ++bcnt;
      lim = T[i]+K;
    }
  }
  if(pcnt!=N)++bcnt;
  cout << bcnt << endl;

  return 0;
}
