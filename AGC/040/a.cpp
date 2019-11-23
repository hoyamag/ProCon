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
  string S;
  cin >> S;
  int N = S.length() + 1;
  VEC<int> A(N, 0);
  int i = 0;
  while (i < N - 1) {
    while (S[i] == '<') {
      A[i + 1] = A[i] + 1;
      i++;
    }
    // DUMP(i, A);
    int j = i;
    while (S[j] == '>') {
      j++;
    }
    int m = j - i;
    REP(k, 0, m) { A[j - k] =  k; }
    A[i] = max(A[i], j - i);
    // DUMP(i, j, A);
    i = j;
  }
  // DUMP(A);
  LL sum = 0;
  // int base = (A[N - 1] < 0 ? abs(A[N - 1]) : 0);
  // A[N - 1] += base;
  // VEC<int> B(A);
  // for (int i = N - 2; i >= 0; i--) {
  //   if (base == 0) {
  //     if (A[i] < 0) {
  //       base = abs(A[i]);
  //       A[i] += base;
  //     }
  //   } else {
  //     if (S[i] == '>') {
  //       A[i] += base;
  //     } else {
  //       base = 0;
  //     }
  //   }
  // }
  REP(i, 0, N) sum += A[i];
  // DUMP(A);
  cout << sum << endl;

  return 0;
}
