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
bool disposable(int k, int discarded, VEC<int> a) {
  int n = a.size();
  bool dp[n + 1][k + 1];
  REPC(i,0,n){REPC(j,0,k){dp[i][j]=0;}}

  dp[0][0] = 1;
  REPC(i, 1, n) {
    REPC(j, 0, k) {
      int item = a[i-1];
      if (j - item >= 0)
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - item];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  // cerr<<endl;
  // REPC(i, 0, n) {
  //   REPC(j, 0, k) { cerr << dp[i][j] << " "; }
  //   cerr << endl;
  // }
  //   cerr << endl;
  REP(i, max(0,k - discarded), k) if (dp[n][i]) { return 0; }
  return 1;
}

int main() {
  int n, k;
  cin >> n >> k;
  VEC<int> a(n);
  REP(i, 0, n) cin >> a[i];
  sort(ALL(a));
  // DUMP(a);
  int deletable = 0, necessary = n;
  VEC<int> b(n - 1);
  int mid;
  while (abs(necessary - deletable) > 1) {
    mid = (deletable + necessary) / 2;
    int cnt = 0;
    REP(i, 0, n) {
      if (i != mid) {
        b[cnt] = a[i];
        ++cnt;
      }
    }
    // DUMP(deletable, mid, necessary, ":", a[mid], b);
    if (disposable(k, a[mid], b)) {
      // DUMP(a[mid],"is deletable");
      deletable = mid;
    } else
      necessary = mid;
  }
  cout << necessary << endl;
  return 0;
}
