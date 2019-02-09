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
ULL str2ULL(string s) {
  int n = s.length();
  ULL ans = 0;
  ULL bin = 1;
  for (int i = n - 1; i >= 0; --i) {
    ans += s[i] * bin;
    bin *= 2;
  }
  return ans;
}
string ULL2str(ULL a) {
  bitset<64> x(a);
  return x.to_string();
}

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  REP(i, 0, n) {
    if (s[i] == 'b')
      s[i] = 0;
    else
      s[i] = 1;
  }
  REP(i, 0, m) {
    if (t[i] == 'b')
      t[i] = 0;
    else
      t[i] = 1;
  }
  ULL sv = str2ULL(s);
  ULL tv = str2ULL(t);
  DUMP(sv, tv);

  string ans = ULL2str(sv + tv);
  DUMP(ans);
  int i = 0;
  while (ans[i] == '0') {
    ++i;
  }
  while (i < ans.length()) {
    if (ans[i] == '0')
      std::cout << 'b';
    else
      std::cout << 'B';
    ++i;
  }
  cout<<endl;

  return 0;
}

