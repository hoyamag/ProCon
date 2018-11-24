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

int H, W, K;
LL M = 1e9 + 7;
VEC<VEC<bool>> path;

LL modpow(LL n, LL p) {
  LL ans = 1;
  REP(i, 0, p) { ans = (ans * n) % M; }
  return ans;
}
void show() {
  REP(i, 0, H) {
    REP(j, 0, W) { cerr << path[i][j] << " "; }
    cerr << endl;
  }
  cerr << endl;
}
// VEC<VEC<bool>> copy(VEC<VEC<bool>>src){
//   VEC<VEC<bool>>a(src.size());
//   REP(i,0,src.size()){
//     a[i]=src[i];
//   }
//   return a;
// }

LL dfs(int h, int w) {
  //DUMP(h, w);
  //show();
  if (h == H - 1 && w == K) {
    LL cnt = 0;
    REP(i, 0, H) {
      REP(j, 0, W) {
        if (!path[i][j]) ++cnt;
      }
    }
    LL ans = modpow(2, cnt);
    //DUMP(ans);
    return ans;
  } else {
    LL ans = 0;
    VEC<pair<int, int>> d = {{h + 1, w}, {h + 1, w - 1}, {h + 1, w + 1}};
    for (auto v : d) {
      int nh = v.first;
      int nw = v.second;
      if (nh < H && 0 <= nw && nw < W && path[nh][nw] == 0) {
        if (nw == w) {
          auto pre = path;
          path[nh][nw] = 1;
          path[h][w] = 1;
          ans = (ans + dfs(nh, nw)) % M;
          path = pre;
        } else {
          auto pre = path;
          path[h][w] = 1;
          path[nh][nw] = 1;
          if (w - 1 >= 0) {
            path[h][w - 1] = 1;
          }
          if (w + 1 < W) {
            path[h][w + 1] = 1;
          }
          ans = (ans + dfs(nh, nw)) % M;
          path = pre;
        }
      }
    }
    //DUMP(ans);
    return ans;
  }
}

int main() {
  cin >> H >> W >> K;
  ++H;
  --K;
  path = MATINIT(bool, H, W, 0);
  if(W!=1)REP(i, 0, H) { path[i][W - 1] = 1; }
  REP(i, 0, W) { path[H - 1][i] = 1; }
  path[H - 1][K] = 0;
  //show();
  LL ans = dfs(0, 0);
  cout << ans << endl;
}