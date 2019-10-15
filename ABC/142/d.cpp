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

bool isPrime(
    int n) { /* returns whether n is prime number or not * n should be in range
                [0, lim]. * to see detail, search 'Sieve of Eratosthenes' */
  static int lim = 1e5;
  static bool done = false;
  static vector<bool> isp(lim + 1, 1);
  if (!done) {
    isp[0] = isp[1] = false;
    for (int i = 2; i <= lim; i++) {
      if (isp[i]) {
        for (int j = i + i; j <= lim; j += i) {
          isp[j] = false;
        }
      }
    }
    done = true;
  }
  return isp[n];
}
std::map<long long, long long> primeFactorization(
    long long n) { /* prime factorization * nを素因数分解する */
  std::map<long long, long long> pf;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      ++pf[i];
    }
  }
  if (n > 1) {
    ++pf[n];
  }
  return pf;
}

int main() {
  LL A,B;
  cin>>A>>B;
  auto ma = primeFactorization(A);
  auto mb = primeFactorization(B);
  // DUMP(ma);
  // DUMP(mb);
  LL cnt= 1;
  for(auto va:ma){
    if(mb[va.first]!=0)cnt++;
  }
  cout<<cnt<<endl;


  return 0;
}
