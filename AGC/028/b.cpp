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
LL M = 1e9+7;
LL kai(LL n){
  static VEC<LL> d(1e5+1,0);
  if(d[n]==0){
    d[0]=1;
    REP(i,1,1e5+1){
      d[i]=(i*d[i-1])%M;
    }
  }
  return d[n];
  
}
void show(MAT<LL> a){
  REP(i,0,a.size()){
    REP(j,0,a[i].size()){
      cerr<<a[i][j]<<" ";
    }
    cerr<<endl;
  }
}

int main() {
  int n;
  cin>>n;
  MAT<LL> m = MATINIT(LL, n+1, n+1,0);
  m[1][1]=1;
  REPC(i,1,n){
    REPC(j,1,n){
      LL sum =kai(i-1);
      REP(k,0,i){
        sum+=kai(n-1)*m[i][j];
      }
      m[i][j]=sum;
    }
  }
  show(m);

  

  return 0;
}
