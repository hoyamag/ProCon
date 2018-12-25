#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m)
    os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
long long gcd(long long a, long long b) {
  // the greatest common divisor
	while (b != 0) {
		long long r = a%b;
		a = b;
		b = r;
	}
	return a;
}
long long lcm(long long a, long long b) {
  //the least common multiple
	return (a / gcd(a, b))*b;
}
#include <cmath>
#include <map>
std::map<long long, long long> primeFactorization(long long n) {
  // 素因数分解
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
  LL n,p;
  cin>>n>>p;
  auto pf = primeFactorization(p);
  LL ans = 1;
  for(auto v:pf){
    if(v.second>=n){
      ans*=pow(v.first, v.second/n);
    }
  }
  cout<<ans<<endl;

  return 0;
}
