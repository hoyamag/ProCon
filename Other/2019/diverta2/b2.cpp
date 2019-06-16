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
const int MAXN = 50;
const int inf = 1 << 30;
VEC<VEC<LL>> X;
VEC<VEC<LL>> Y;
void show(VEC<VEC<int>> M) {
  REP(i, 0, M.size()) { DUMP(M[i]); }
}

int main() {
  LL N;
  cin >> N;
  if (N == 1 || N == 2) {
    cout << 1 << endl;
    return 0;
  }
  X = MATINIT(LL, N, N, inf);
  Y = MATINIT(LL, N, N, inf);
  REP(i, 0, N) {
    X[i][i] = 0;
    Y[i][i] = 0;
  }
  VEC<pair<LL, LL>> C(N);

  VEC<LL> x(N), y(N);
  REP(i, 0, N) {
    std::cin >> x[i] >> y[i];
    C[i].first = x[i];
    C[i].second = y[i];
  }
  sort(ALL(C));
  queue<pair<LL, LL>> Q;
  REP(i, 0, N) {
    REP(j, 0, N) {
      if (i == j) continue;
      X[i][j] = x[j] - x[i];
      Y[i][j] = y[j] - y[i];
      Q.push({X[i][j], Y[i][j]});
    }
  }
  LL count = 0;
  while (!Q.empty()) {
    LL p = Q.front().first;
    LL q = Q.front().second;
    Q.pop();
    // DUMP("begin, i,j,p,q", i, j, p, q);
    LL cnt = 0;
    VEC<bool> used(N, false);
    REP(i, 0, N) {
      LL x = C[i].first;
      LL y = C[i].second;
      REP(j, 0, N) {
        if (used[j]) continue;
        LL nx = C[j].first;
        LL ny = C[j].second;
        if (nx - x == p && ny - y == q) {
          cnt++;
          used[j] = 1;
        }
      }
      count = max(count, cnt);
    }
  }
  cout << N - count << endl;

  return 0;
}
