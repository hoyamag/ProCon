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

int dfs(int N, int a, int b, int c, const VEC<int> &L, VEC<char> g) {
  if ((int)g.size() == N) {
    int A, B, C;
    A = B = C = -10;
    int la, lb, lc;
    la = lb = lc = 0;
    REP(i, 0, g.size()) {
      if (g[i] == 'A') {
        A += 10;
        la += L[i];
      } else if (g[i] == 'B') {
        B += 10;
        lb += L[i];
      } else if (g[i] == 'C') {
        C += 10;
        lc += L[i];
      }
    }
    A = max(0, A);
    B = max(0, B);
    C = max(0, C);
    if (la > 0 && lb > 0 && lc > 0) {
      int ans = A + abs(a - la) + B + abs(b - lb) + C + abs(c - lc);
    //   DUMP(g, ans, A, B, C, la, lb, lc);
      return ans;
    }
    return 1<<30;
  } else {
    int mi = 1 << 30;
    REP(i, 0, 4) {
      VEC<char> tmp = g;
      tmp.push_back('A' + i);
      int cand = dfs(N, a, b, c, L, tmp);
      mi = min(mi, cand);
    }
    return mi;
  }
}

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  VEC<int> L(N);
  REP(i, 0, N) cin >> L[i];
  VEC<char> tmp;
  int ans = dfs(N, A, B, C, L, tmp);
  cout << ans << endl;

  return 0;
}
