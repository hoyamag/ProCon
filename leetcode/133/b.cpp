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

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    LL sum = 0;
    int inf = 1 << 30;
    int N = costs.size();

    vector<vector<int>> dp =
        vector<vector<int>>(N + 1, vector<int>(N + 1, inf));
    dp[0][0] = 0;
    dp[1][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    REP(k, 1, N) {
      REP(i, 0, (int)k + 1) {
        int j = k - i;
        if (i < N && j < N) {
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + costs[k][0]);
          dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + costs[k][1]);
          // DUMP(k, i, j, "dp[i][j]", dp[i][j],"dp[i+1][j]", dp[i + 1][j], "dp[i][j+1]", dp[i][j + 1]);
        }
      }
    }
    return dp[N / 2][N / 2];
  }
};

int main() {
  auto a = Solution();
  VEC<VEC<int>> v(4);
  v[0] = {10, 20};
  v[1] = {30, 200};
  v[2] = {400, 50};
  v[3] = {30, 20};
  cout << a.twoCitySchedCost(v) << endl;
  ;

  return 0;
}
