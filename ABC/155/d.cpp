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
LL Count(string s) {
  int n = s.length();
  LL sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    int k = s[i] - '0';
    sum += k;
  }
  return sum;
}
string Next(string s, int keta) {
  int n = s.length();
  string ret = s;
  if (keta == -1) {
    return "10" + s.substr(2, n - 2);
  }

  int k = s[keta] - '0';
  if (k != 9) {
    ret[keta] = k + 1 + '0';
    return ret;
  } else {
    ret[keta] = '0';
    return Next(ret, keta - 1);
  }
}

int main() {
  string S;
  cin >> S;
  int N = S.length();
  REP(i, N, N + 100) { 
    string v = Next(S, N-1);
    DUMP(v);
  }

  return 0;
}
