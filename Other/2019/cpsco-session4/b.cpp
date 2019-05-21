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
int Sum(string S) {
  int sum = 0;
  REP(i, 0, S.length()) {
    if (S[i] == 'o') {
      sum++;
    }
  }
  return sum;
}
int dfs(VEC<string> S, int date, int remain) {
  if (remain == 0) {
    return Sum(S[date]);
  }
  int N = S[0].length();
  int D = S.size();
  int si = Sum(S[date]);
  REP(i, date + 1, D) {
    REP(j, 0, N) {
      if (S[date][j] == 'o') S[i][j] = 'x';
    }
  }
  int sj = 0;
  for (int i = date + 1; i < D; i++) {
    sj = max(sj, dfs(S, i, remain - 1));
  }
  return si+sj;
}

int main() {
  int N, D;
  cin >> N >> D;
  VEC<string> S(D);
  REP(i, 0, D) cin >> S[i];
  int ma = 0;
  // REP(i, 0, N) {
  //   int si = Sum(S[i]);
  //   REP(j, i + 1, N) {
  //     int sj = Sum(S[j]);
  //     ma = max(ma, si + sj);
  //   }
  // }
  REP(i,0,D-1){
    ma=max(ma, dfs(S,i,1));
  }
  cout << ma << endl;

  return 0;
}
