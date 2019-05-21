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
LL N, K;
LL dfs(LL x, LL y, VEC<LL> bar) {
  // DUMP(x, y, bar);
  if (bar.size() == 0) {
    if (y - x <= K && x <= y) {
      return 1;
    }
    return 0;
  }
  if (y - x >  K) return 0;
  LL cnt = 0;
  LL t = bar.back();
  bar.pop_back();
  cnt += dfs(x, y, bar);
  cnt += dfs(x + (1 << t), y, bar);
  cnt += dfs(x, y + (1 << t), bar);
  return cnt;
}

const LL MAX_N = 1e5;
int main() {
  cin >> N >> K;
  LL Y = 1;
  LL X = 0;
  while (Y <= N) {
    X += Y;
    Y <<= 1;
  }
  Y += N;
  // DUMP(X,Y,K);
  if (Y - X <= K) {
    cout << "INF" << endl;
    return 0;
  }

  LL bit = 0;
  VEC<LL> bar;
  while ((1 << bit) <= MAX_N) {
    if (((1 << bit) & N) == 0) {
      bar.push_back(bit);
    }
    ++bit;
  }
  // DUMP(bar);
  LL ans = dfs(N, N, bar);
  cout << ans << endl;

  return 0;
}
