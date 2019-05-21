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
int dfs(int k, int start, LL sum, const VEC<LL> &A) {
  if (k == 0) {
    // DUMP(sum, coin_num(sum));
    return coin_num(sum);
  }
  int mi = INT32_MAX;
  REP(i, start, A.size() - k + 1) {
    mi = min(mi, dfs(k - 1, i + 1, sum + A[i], A));
  }
  return mi;
}

int main() {
  int N, K;
  cin >> N >> K;
  VEC<LL> A(N, -1);
  REP(i, 0, N) { cin >> A[i]; }
  cout << dfs(K, 0, 0, A) << endl;

  return 0;
}
