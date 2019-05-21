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
int coin_num(LL v) {
  int cnt = 0;
  while (v > 0) {
    int p = v % 10;
    if (p >= 5) {
      cnt++;
      p -= 5;
    }
    cnt += p;
    v /= 10;
  }
  return cnt;
}

int main() {
  int N, K;
  cin >> N >> K;
  VEC<LL> A(N + 1, -1);
  REP(i, 1, N + 1) { cin >> A[i]; }
  pair<int, LL> dp[N + 1][K + 1];
  const int inf = 1 << 30;
  REP(i, 0, N + 1) {
    REP(j, 0, K + 1) {
      if (j == 1) {
        dp[i][j] = {coin_num(A[i]), A[i]};
      } else {
        dp[i][j] = {inf, -1};
      }
    }
  }
  REP(i, 1, N + 1) {
    REP(j, 1, min(i, (LL)K + 1)) {
      LL tsum = dp[i - 1][j - 1].second + A[i];
      LL tcnt = coin_num(tsum);

      if (dp[i][j].first > tcnt) {
        dp[i][j] = {tcnt, tsum};
      }

      tsum = dp[i - 1][j].second;
      tcnt = dp[i - 1][j].first;
      if (dp[i][j].first > tcnt) {
        dp[i][j] = {tcnt, tsum};
      }
    }
  }
  cout << dp[N][K].first << endl;

  return 0;
}
