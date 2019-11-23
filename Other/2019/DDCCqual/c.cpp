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
void show(int H, int W, VEC<VEC<int>>&A){
  REP(i,0,H){
    REP(j,0,W){
      cout<<A[i][j]<<" ";
    }
    cout<<endl;
  }
  cerr<<endl;

}

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  VEC<string> S(H);
  REP(i, 0, H) cin >> S[i];
  auto A=MATINIT(int, H, W, 0);
  int k = 1;
  REP(i,0,H){
    REP(j,0,W){
      if(S[i][j]=='#'){
        A[i][j]=k;
        k++;
      }
    }
  }
  // show(H,W,A);

  REP(i,0,H){
    REP(j,1,W){
      int prev = A[i][j-1];
      if(prev!=0 && A[i][j]==0)A[i][j]=prev;
    }
    for(int j=W-2;j>=0;j--){
      int prev = A[i][j+1];
      if(prev!=0 && A[i][j]==0)A[i][j]=prev;
    }
  }
  // show(H,W,A);

  REP(j,0,W){
    REP(i,1,H){
      int prev = A[i-1][j];
      if(prev!=0 && A[i][j]==0)A[i][j]=prev;
    }
    for(int i=H-2;i>=0;i--){
      int prev = A[i+1][j];
      if(prev!=0 && A[i][j]==0)A[i][j]=prev;
    }
  }
  show(H,W,A);

  return 0;
}
