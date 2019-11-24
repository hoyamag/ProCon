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

int main() {
  LL H, W, K, V;
  cin >> H >> W >> K >> V;
  auto A = VEC<VEC<LL>>(H, VEC<LL>(W, 0));
  REP(h, 0, H) {
    REP(w, 0, W) {
      cin >> A[h][w];
      A[h][w] += K;
    }
  }
  auto cost = VEC<VEC<LL>>(H, VEC<LL>(W, 0));
  REP(h, 0, H) {
    cost[h][0] = A[h][0];
    REP(w, 1, W) { cost[h][w] = A[h][w] + cost[h][w - 1]; }
  }
  REP(w, 0, W) {
    REP(h, 1, H) { cost[h][w] += cost[h - 1][w]; }
  }

  // cerr << endl;
  // REP(h, 0, H) {
  //   REP(w, 0, W) { cerr << cost[h][w] << " "; }
  //   cerr << endl;
  // }
  // cerr << endl;

  LL ans = 0;
  REP(h, 0, H) {
    REP(w, 0, W) {
      REP(nh, h, H) {
        REP(nw, w, W) {
          ULL c = cost[nh][nw];
          if (w - 1 >= 0) c -= cost[nh][w - 1];
          if (h - 1 >= 0) c -= cost[h - 1][nw];
          if (h - 1 >= 0 && w - 1 >= 0) c += cost[h - 1][w - 1];

          // DUMP(h,w,nh,nw,c);
          if (c <= V) {
            LL area = (nh + 1 - h) * (nw + 1 - w);
            ans = max(ans, area);
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
