#include <bits/stdc++.h>
#define REP(i, a, n) for (long long i = (a); i < (long long)(n); ++i)
#define REPC(i, a, n) for (long long i = (a); i <= (long long)(n); ++i)
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
void show(VEC<VEC<int>>M){
  REP(i,0,M.size()){
    DUMP(M[i]);
  }
}

int main() {
  int H,W;
  cin>>H>>W;
  VEC<string>S(H);
  REP(i,0,H)cin>>S[i];
  auto WMAT = MATINIT(int, H, W, 0);
  auto HMAT = MATINIT(int, H, W, 0);
  REP(h,0,H){
    int num = 0;
    REP(w,0,W){
      if(S[h][w]=='#'){
        num=0;
        continue;
      }
      num++;
      WMAT[h][w]=num;
    }
    for(int w=W-2;w>=0;w--){
      if(WMAT[h][w]!=0)WMAT[h][w]=max(WMAT[h][w], WMAT[h][w+1]);
    }
  }
  // show(WMAT);
  // DUMP();

  REP(w,0,W){
    int num = 0;
    REP(h,0,H){
      if(S[h][w]=='#'){
        num=0;
        continue;
      }
      num++;
      HMAT[h][w]=num;
    }
    for(int h=H-2;h>=0;h--){
      if(HMAT[h][w]!=0)HMAT[h][w]=max(HMAT[h][w], HMAT[h+1][w]);
    }
  }
  // show(HMAT);
  int ma = 0;

  REP(h,0,H){
    REP(w,0,W){
      ma=max(ma, HMAT[h][w]+WMAT[h][w]);
    }
  }
  cout<<ma-1<<endl;


  return 0;
}
