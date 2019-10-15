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

int N;
int main() {
  string S;
  cin >> S;
  N = S.length();
  VEC<int> C;
  int row = 1;
  REP(i, 0, N - 1) {
    if (S[i] != S[i + 1]) {
      C.push_back(row);
      row = 1;
    } else {
      row++;
    }
  }
  C.push_back(row);
  //   DUMP(C);
  auto calc = [&](int i) -> int {
    return  i / 3 * 2 + (i % 3 > 0 ? 1 : 0);
  };
  int cnt = 0;
  REP(i, 0, C.size() - 1) {
      if (C[i] % 3 >= 2 && C[i + 1] % 3 >= 2) {
        C[i]--;
        C[i + 1]--;
        cnt++;
      }
  }
  LL sum = 0;
  REP(i, 0, C.size()) {
    int s = C[i] / 3 * 2 + (C[i] % 3 > 0 ? 1 : 0);
    sum += s;
  }
  //   DUMP("cnt, sum:", cnt, sum);
  cout << cnt + sum << endl;

  return 0;
}
