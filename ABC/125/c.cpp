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
bool isPrime(int n) {
  if (n <= 3) return 1;
  for (int i = 2; i * i <= n; i += 1) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int N;
  cin >> N;
  VEC<LL> A(N);
  LL ma = 0;
  REP(i, 0, N) {
    cin >> A[i];
    ma = max(ma, A[i]);
    // cout << isPrime(A[i]) << endl;
  }
  // REP(i,2,100){
  //   cout<<i<<" "<<isPrime(i)<<endl;
  // }
  LL ans = 1;
  LL fixed = 1;
  for (int p = 2; p * p <= ma; ++p) {
    if (!isPrime(p)) continue;
    int cnt = 0;
    REP(i, 0, N) {
      if (A[i] % p != 0) {
        ++cnt;
      }else{
        A[i]/=p;
      }
    }
    if (cnt == 0) {
      ans *= p;
      fixed *= p;
      p--;
    } else if (cnt == 1) {
      fixed = max(fixed, ans * p);
    }
    // DUMP(p, cnt, ans, fixed);
  }
  cout << fixed << endl;

  return 0;
}
