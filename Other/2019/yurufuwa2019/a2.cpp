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
  char b = 'b';
  char B = 'B';
  stringstream st;
  if (n > m) {
    REP(i, 0, n - m) { st << 'b'; }
    st << t;
    t = st.str();
  } else {
    REP(i, 0, m - n) st << 'b';
    st << s;
    s = st.str();
  }
  DUMP(s, t);

  list<char> ans;
  bool carry = 0;
  for(int i=max(n,m)-1;i>=0;i--){
    char push;
    if (!carry) {
      if (s[i] == 'b' && t[i] == 'b') {
        push = b;
        carry = 0;
      } else if (s[i] == 'B' && t[i] == 'B') {
        push = b;
        carry = 1;
      } else {
        push = B;
        carry = 0;
      }
    } else {
      if (s[i] == 'b' && t[i] == 'b') {
        push = B;
        carry = 0;
      } else if (s[i] == 'B' && t[i] == 'B') {
        push = B;
        carry = 1;
      } else {
        push = b;
        carry = 1;
      }
    }
    // DUMP(carry, push);
    ans.push_front(push);
  }
  if (carry) ans.push_front('B');
  for (auto v : ans) {
    cout << v;
  }
  cout << endl;

  return 0;
}
