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
VEC<int> typenum(string s) {
  int n = s.length();
  map<char, int> m;
  REP(i, 0, n) { m[s[i]]++; }
  VEC<int> ans;
  for (char c = 'a'; c <= 'z'; c++) {
    if (m[c] != 0)
      ans.push_back(m[c]);
  }
  return ans;
}
bool vecequ(VEC<int> s, VEC<int> t) {
  REP(i, 0,s.size()) {
    if (s[i] != t[i])
      return 0;
  }
  return 1;
}

int main() {
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }
  int n = s.length();
  VEC<int> st(n, 0), tt(n, 0);
  map<char, int> sm, tm;
  int sc = 0, tc = 0;
  REP(i, 0, n) {
    if (sm[s[i]] == 0) {
      sc++;
      sm[s[i]] = sc;
      st[i] = sm[s[i]];
    }else{
      st[i] = sm[s[i]];
    }
    if (tm[t[i]] == 0) {
      tc++;
      tm[t[i]] = tc;
      tt[i] = tm[t[i]];
    }else{
      tt[i] = tm[t[i]];
    }
  }
  //DUMP(st, tt);
  //sort(ALL(st));
  //sort(ALL(tt));
  Yes(vecequ(st, tt));

  return 0;
}
