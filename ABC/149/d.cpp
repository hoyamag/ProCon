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
int rock = 0, sizz = 1, par = 2;

int Point(int R, int S, int P, char opponent, int mine) {
  if (opponent == 'r') {
    if (mine == par) return P;
  } else if (opponent == 's') {
    if (mine == rock) return R;
  } else {
    if (mine == sizz) return S;
  }
  return 0;
}

int ProbS(int R, int S, int P, string T2) {
  int N = T2.size();
  // VEC<VEC<int>> dp = VEC<VEC<int>>(N, VEC<int>(3, 0));
  // dp[0][rock] = Point(R, S, P, T2[0], rock);
  // dp[0][sizz] = Point(R, S, P, T2[0], sizz);
  // dp[0][par] = Point(R, S, P, T2[0], par);

  // REP(i, 1, N) {
  //   int pr = Point(R, S, P, T2[i], rock);
  //   int ps = Point(R, S, P, T2[i], sizz);
  //   int pp = Point(R, S, P, T2[i], par);
  //   dp[i][rock] = max({dp[i - 1][par] + pr, dp[i - 1][sizz] + pr});
  //   dp[i][sizz] = max({dp[i - 1][par] + ps, dp[i - 1][rock] + ps});
  //   dp[i][par] = max({dp[i - 1][rock] + pp, dp[i - 1][sizz] + pp});
  // }

  map<char, char> wins = {{'r', 'p'}, {'s', 'r'}, {'p', 's'}};
  map<char, int> points = {{'r', R}, {'s', S}, {'p', P}};
  char prev = ' ';
  LL sum = 0;
  REP(i, 0, N) {
    char oppo = T2[i];
    char mine = wins[oppo];
    if (mine != prev) {
      sum += points[mine];
      prev = mine;
    } else {
      prev = ' ';
    }
  }
  return sum;

  // return max({dp[N - 1][rock], dp[N - 1][sizz], dp[N - 1][par]});
}

int main() {
  int N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  VEC<string> subs(K, "");
  // DUMP("HI");
  REP(i, 0, N) { subs[i % K].push_back(T[i]); }

  // DUMP("HI2");

  LL sum = 0;
  REP(i, 0, K) { sum += ProbS(R, S, P, subs[i]); }
  cout << sum << endl;

  return 0;
}
