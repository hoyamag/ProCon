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
int n;
string s;
VEC<int> csm;
LL dmc(int dis) {
  LL ret = 0;
  REP(pos, 0, n) {
    int mnum = 0;
    if(pos+dis>=n)break;
    if (s[pos] == 'D' && s[pos + dis] == 'C') {
      mnum = csm[pos+dis-1]-csm[pos];
      ret += mnum;
      //DUMP(dis, ret,mnum);
    }
  }
  return ret;
}

int main() {
  int q;
  cin >> n >> s >> q;
  VEC<int> k(q);
  REP(i, 0, q) cin >> k[i];
  int kmax = n;
  csm = VEC<int>(n, 0);
  REP(i, 1, n) { csm[i] = csm[i - 1] + (s[i] == 'M' ? 1 : 0); }
  //DUMP(csm);

  VEC<LL> dp(kmax+1, 0);
  
  REP(i, 2, kmax + 1) { dp[i] = dp[i - 1] + dmc(i); }
  //DUMP(dp);

  REP(i,0,q){
    cout<<dp[k[i]-1]<<endl;
  }

  return 0;
}
