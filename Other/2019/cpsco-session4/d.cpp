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
  int N, K;
  cin >> N >> K;
  VEC<int> A(N + 1, -1);
  REP(i, 0, N) cin >> A[i];
  VEC<int> s;
  int cnt = 1;
  REP(i, 1, N + 1) {
    if (A[i] != A[i - 1]) {
      s.push_back(cnt);
      cnt = 0;
    }
    ++cnt;
  }

  auto valid = [&](int ans) -> bool {
    int kcnt = 0;
    REP(i, 0, s.size()) {
      if (s[i] > ans) {
        kcnt += s[i] / (ans + 1);
      }
    }
    if (kcnt <= K) {
      return 1;
    }
    return 0;
  };
  int ng = 0;
  int ok = N;

  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
    // DUMP(ok, ng, mid, valid(mid));
    if (valid(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
