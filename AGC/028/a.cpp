#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
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
long long gcd(long long a, long long b) {
  // the greatest common divisor
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) {
  // the least common multiple
  return (a / gcd(a, b)) * b;
}

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int size = lcm(n, m);
  VEC<char> ans;
  for (int i = size; i < 100 * size; i += size) {
    ans = VEC<char>(i, 'z');
    int u = i / n;
    int k = 0;
    for (int j = 0; j < i; j += u) {
      ans[j] = s[k];
      ++k;
    }
    u = i / m;
    k = 0;
    for (int j = 0; j < i; j += u) {
      ans[j] = t[k];
      ++k;
    }
    u = i / n;
    k = 0;
    bool ok = 1;
    for (int j = 0; j < i; j += u) {
      if (ans[j] != s[k]) {
        ok = 0;
        break;
      }
      ++k;
    }
    if (ok) {
      cout<<i<<endl;
      //REP(j, 0, i) cerr << ans[j];
      //cerr<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;

  return 0;
}
