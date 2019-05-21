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
ostream &operator<<(ostream &os, list<T> &vec) {
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
const int lim = 200;
struct result {
  bool loose;
  VEC<int> remain;
  VEC<int> looser;
};
int compare(char a, char b) {
  if (a == b) return 0;
  if (a == 'S') {
    if (b == 'P')
      return 1;
    else
      return -1;
  }
  if (a == 'P') {
    if (b == 'R')
      return 1;
    else
      return -1;
  }
  if (a == 'R') {
    if (b == 'S')
      return 1;
    else
      return -1;
  }
  return -2;
}
result match(char my, VEC<char> op, VEC<int> number) {
  result res;
  res.loose = 0;
  int index = 0;
  for (auto v : op) {
    int c = compare(my, v);
    if (c == 1) {
      res.looser.push_back(number[index]);
    } else if (c == 0) {
      res.remain.push_back(number[index]);
    } else if (c == -1) {
      res.loose = 1;
    } else {
      DUMP("wrong");
    }
    index++;
  }
  DUMP("match", my, op, number, res.looser, res.remain, res.loose);
  return res;
}
list<char> ans;
bool dfs(int round, VEC<string> C, VEC<int> remain) {
  if (round > lim) return 0;
  if (remain.size() == 0) return 1;
  DUMP(round, C, remain, ans);
  VEC<char> oppo;
  for (auto v : remain) {
    string s = C[v];
    oppo.push_back(s[round % s.length()]);
  }
  auto P = match('P', oppo, remain);
  if (P.loose == 0) {
    if (dfs(round + 1, C, P.remain)) {
      ans.push_front('P');
      return 1;
    }
  }
  auto S = match('S', oppo, remain);
  if (S.loose == 0) {
    if (dfs(round + 1, C, S.remain)) {
      ans.push_front('S');
      return 1;
    }
  }
  auto R = match('R', oppo, remain);
  if (R.loose == 0) {
    if (dfs(round + 1, C, R.remain)) {
      ans.push_front('R');
      return 1;
    }
  }
  return 0;
}
void solve(int test) {
  int A;
  cin >> A;
  VEC<string> C(A);
  REP(i, 0, A) { cin >> C[i]; }
  VEC<int> r(A);
  REP(i, 0, A) { r[i] = i; }

  cout << "Case #" << test + 1 << ": ";
  if (dfs(0, C, r)) {
    for (auto v : ans) {
      cout << v;
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}

int main() {
  int T;
  cin >> T;
  REP(i, 0, T) {
    ans = {};
    // cerr<<endl;
    solve(i);
  }

  return 0;
}
