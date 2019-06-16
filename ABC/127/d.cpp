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
  int N, M;
  cin >> N >> M;
  VEC<LL> A(N);
  REP(i, 0, N) cin >> A[i];
  VEC<pair<LL, LL>> B(M);
  REP(i, 0, M) { cin >> B[i].second >> B[i].first; }
  sort(ALL(A));
  sort(ALL(B), greater<pair<LL, LL>>());
  // DUMP(A);
  // DUMP(B);

  // DUMP("HI");
  int count = 0;
  int j = 0;
  REP(i, 0, M) {
    // DUMP(i);
    while (B[i].second > 0) {
      // DUMP(A);
      if (B[i].first > A[j]) {
        A[j] = B[i].first;
        B[i].second--;
        j++;
        count++;
      } else {
        break;
      }
    }
  }
  LL sum = 0;
  REP(i, 0, N) { sum += A[i]; }
  cout << sum << endl;

  return 0;
}
