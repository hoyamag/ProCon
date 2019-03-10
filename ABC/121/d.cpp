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
template <typename T> ostream &operator<<(ostream &os, set<T> &s) {
  os << "{";
  for (auto p : s)
    os << p << ",";
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

const LL lim = 1e12;
int main() {
  LL A, B;
  cin >> A >> B;
  cerr << log2(1e12) << endl;
  VEC<LL> syuki;
  bitset<64> K(A);
  LL i = 2;
  while (i < lim) {
    syuki.push_back(i);
    i *= 2;
  }
  cout << K << endl;
  DUMP(syuki);
  int n = syuki.size();
  string bits;
  REP(i, 0, n) {
    LL T = syuki[i];
    LL a = A % T;
    LL b = B % T;
    LL oneNum = 0;
    if (a == b) {
      oneNum = T / 2;
    }
    if (a < b) {
      if (b >= T / 2) {
        oneNum += a < T / 2 ? b - T / 2 + 1 : b - a + 1;
      }
    } else {
      if (a >= T / 2) {
        oneNum += T - a;
      }
      if (b >= T / 2) {
        oneNum += b - T / 2 + 1;
      }
    }
    int thisBit = 0;
    if (oneNum % 2 == 0) {
      thisBit = K[i];
    } else {
      thisBit = !K[i];
    }
    bits.push_back(thisBit + '0');
    DUMP(i, oneNum);
  }
  cout << bits << endl;

  return 0;
}
