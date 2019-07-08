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

double dist(VEC<int> a, VEC<int> b) {
  LL sum = 0;
  REP(i, 0, a.size()) { sum += abs(a[i] - b[i])*abs(a[i]-b[i]); }
  return sum;
}
bool isPow(double a){
  static VEC<int> v(1e6+1,-1);
  if(v[a]!=-1)return v[a];
  int p = 0;
  REP(i,1,sqrt(a)+1){
    p=i*i;
    if(p==a){v[a]=1;return 1;}

  }
  v[a]=0;
  return 0;
}
int main() {
  int N, D;
  cin >> N >> D;
  VEC<int> X[N];
  REP(i, 0, N) {
    X[i] = VEC<int>(D, 0);
    REP(j, 0, D) cin >> X[i][j];
  }
  double eps = 1e-9;
  int cnt = 0;
  REP(i, 0, N) {
    REP(j, i + 1, N) {
      double d = dist(X[i], X[j]);
      // if (abs(ld - d) <= eps) {
        if(isPow(d)){
        cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
