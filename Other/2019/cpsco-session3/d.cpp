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
VEC<bool> used;
string S;
void dfs(int index) {
  if (index < 0 || S.length() <= index) return;
  if (used[index]) return;
  used[index] = 1;
  if (S[index] == 'G') {
    if (index - 1 >= 0 && S[index - 1] == 'R') dfs(index - 1);
    if (index + 1 < S.length() && S[index + 1] == 'B') dfs(index + 1);
  } else if (S[index] == 'R') {
    if (index - 1 >= 0 && S[index - 1] == 'R') dfs(index - 1);
  } else {
    if (index + 1 < S.length() && S[index + 1] == 'B') dfs(index + 1);
  }
}

int main() {
  int N;
  cin >> N >> S;
  used = VEC<bool>(N, 0);
  REP(i, 1, N) {
    if (S[i] == 'G' && S[i - 1] == 'G') {
      cout << "No" << endl;
      return 0;
    }
  }
  if (S[0] != 'R' || S[N - 1] != 'B') {
    cout << "No" << endl;
    return 0;
  }
  REP(i, 0, N) {
    if (S[i] == 'G') {
      dfs(i);
    }
  }
  REP(i, 0, N) {
    if (used[i] == false) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
