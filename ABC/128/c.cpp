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
int bitcount(int n) {
  int cnt = 0;
  while (n > 0) {
    if ((n & 1) == 1) {
      cnt++;
    }
    n >>= 1;
  }
  return cnt;
}

int main() {
  int N, M;
  cin >> N >> M;
  VEC<int> K(M);
  VEC<VEC<int>> S(M);
  REP(i, 0, M) {
    cin >> K[i];
    S[i] = VEC<int>(K[i]);
    REP(j, 0, K[i]) {
      cin >> S[i][j];
      S[i][j]--;
    }
  }
  VEC<int> P(M);
  REP(i, 0, M) cin >> P[i];
  VEC<int> pattern(M, 0);
  REP(i, 0, M) {
    REP(j, 0, K[i]) { pattern[i] += (1 << S[i][j]); }
  }

  int count =0;
  REP(bit, 0, 1 << N) {
    int all = 1;
    REP(i, 0, M) {
      int on = bit & pattern[i];
      if (bitcount(on) % 2 != P[i]) {
        all = 0;
        break;
      }
    }
    if(all)count++;
  }
  cout<<count<<endl;

  return 0;
}
