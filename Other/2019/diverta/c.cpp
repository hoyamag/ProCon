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
  DUMP("eee");
  int N, a, b, ab, ba;
  a = b = ab = ba = 0;
  cin >> N;
  VEC<string> S(N);
  int ans = 0;
  REP(i, 0, N) {
    cin >> S[i];
    string s = S[i];
    int m = s.length();
    if (s[0] == 'B' && s[m - 1] == 'A')
      ba++;
    else if (s[m - 1] == 'A')
      ++a;
    else if (s[0] == 'B')
      ++b;

    REP(j,1,m){
      if(s[j-1]=='A' &&s[j]=='B')ans++;
    }
  }
  DUMP(a, b, ab, ba, "ans", ans);
  ans+=min(a,b);
  int used = min(a,b);
  if (a > b) {
    int t = min(a - used, ba);
    ans += t;
    ba -= t;
  } else if (a < b) {
    int t = min(b - used, ba);
    ans += t;
    ba -= t;
  }
  DUMP(ans, ba);
  ans += ba / 2;
  cout << ans << endl;

  return 0;
}
