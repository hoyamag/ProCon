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
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
vector<vector<long long>> combTableByPascalsTriangle(int n) {
  //パスカルの三角形を利用した組合せの前計算。O(N^2)。
  // arg...
  //  int n: 組合せ計算したい要素の個数。nCrで指定しうる最大のn
  // return...
  //  vector<vector<long long>> c : 組合せ計算nCrの結果がc[n][r]に入っている。
  auto c = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 or j == i) {
        c[i][j] = 1LL;
      } else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
      }
    }
  }
  return c;
}
bool isPrime(int n) {
  // returns whether n is prime number or not
  // n should be in range [0, lim].
  // to see detail, search "Sieve of Eratosthenes"
  static long long lim = 1e5;
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
LL bunkatu(LL n, LL k, VEC<VEC<LL>> &comb) { return comb[n + k - 1][n]; }

const LL NMAX = 1e5;
const LL MMAX = 1e9;
const LL bigM = (LL)1e9 + 7;
VEC<int> primes;

int main() {
  LL n, m;
  cin >> n >> m;
  REPC(i, 0, min(m,NMAX)) {
    if (isPrime(i)) {
      int j = m;
      int num = 0;
      if (j % i == 0) {
        while (j % i == 0) {
          num++;
          j /= i;
        }
        primes.push_back(num);
      }
    }
  }
  DUMP(primes);
  int pmax = 0;
  int size = primes.size();
  REP(i, 0, size) pmax = max(pmax, primes[i]);
  auto comb = combTableByPascalsTriangle(pmax+n);
  //DUMP(comb);

  LL ans = 1;
  REP(i, 0, size) { ans = (ans * bunkatu(primes[i], n, comb)) % bigM; }
  cout << ans << endl;

  return 0;
}
