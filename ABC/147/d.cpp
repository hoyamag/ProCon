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
const LL M = 1000000007;
void show(VEC<VEC<int>> A) {
  REP(i, 0, A.size()) {
    REP(j, 0, A[i].size()) { cerr << A[i][j] << " "; }
    cerr << endl;
  }
  cerr << endl;
}
LL gbit(LL n, LL i) { return (n >> i) & 1; }

int main() {//AC
  // The way come up with during contest
  LL N;
  cin >> N;
  VEC<LL> A(N);
  REP(i, 0, N) cin >> A[i];
  LL bit_lim = 61;
  // LL lim = pow(2, 60);
  VEC<LL> B(bit_lim, 0);
  VEC<VEC<LL>> bit_cs(bit_lim, VEC<LL>(N));
  REP(bit, 0, bit_lim) {
    bit_cs[bit][0] = gbit(A[0], bit);
    REP(i, 1, N) { bit_cs[bit][i] = gbit(A[i], bit) + bit_cs[bit][i - 1]; }
  }
  // show(bit_cs);
  REP(bit, 0, bit_lim) {
    REP(i, 0, N) {
      LL one_num_raw = bit_cs[bit][N - 1] - bit_cs[bit][i];
      LL one_num;
      if (gbit(A[i], bit) == 0) {
        one_num = one_num_raw;
      } else {
        one_num = N - i - 1 - one_num_raw;
      }
      B[bit] = (B[bit]+one_num)%M;
    }
  }
  LL sum = 0;
  REP(bit, 0, bit_lim) {
    // LL c = 0;
    // LL adding = (1LL << bit);
    // REP(i, 0, B[bit]) { c = (c + adding) % M; }
    LL c = (B[bit] * ((1LL << bit)%M)) % M;
    sum = (sum + c) % M;
  }
  cout << sum << endl;

  return 0;
}
int from_editorial() {//AC
  ULL N;
  cin >> N;
  VEC<ULL> A(N);
  REP(i, 0, N) cin >> A[i];
  ULL bit_lim = 60;
  VEC<ULL> B(bit_lim, 0);
  REP(bit, 0, bit_lim) {
    LL zeros = 0;
    LL ones = 0;
    REP(i, 0, N) {
      if (gbit(A[i], bit)) {
        ones++;
      } else {
        zeros++;
      }
    }
    // zeros=(N-ones);
    B[bit] = (zeros * ones) % M;
  }
  ULL sum = 0;
  REP(bit, 0, bit_lim) {
    ULL c = (1ULL << bit) % M;
    c = (B[bit] * c) % M;
    sum = (sum + c) % M;
  }
  cout << sum << endl;
  return 0;
}
