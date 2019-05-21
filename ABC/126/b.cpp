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
bool isYY(char a, char b) {
  return ('0' <= a && a <= '9') && ('0' <= b && b <= '9');
}
bool isMM(char a, char b) {
  if (a == '0') {
    return '0' <= b && b <= '9';
  } else if (a == '1') {
    return '0' <= b && b <= '2';
  }
  return 0;
}

int main() {
  // cerr<<(double)1/3<<endl;
  string S;
  cin >> S;
  bool maeYY = isYY(S[0], S[1]);
  bool maeMM = isMM(S[0], S[1]);
  bool usiYY = isYY(S[2], S[3]);
  bool usiMM = isMM(S[2], S[3]);

  bool YYMM=0, MMYY=0;

  if(maeYY && usiMM){
    YYMM=1;
  }
  if(maeMM && usiYY){
    MMYY=1;
  }
  DUMP(YYMM, MMYY);
  if(YYMM&& !MMYY){
    cout<<"YYMM";
  }else if(!YYMM && MMYY){
    cout<<"MMYY";
  }else if(YYMM && MMYY){
    cout<<"AMBIGUOUS";
  }else{
    cout<<"NA";
  }
  cout<<endl;
}
