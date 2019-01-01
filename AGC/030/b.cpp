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

int main() {
  LL N, L;
  cin >> L >> N;
  VEC<LL> X(N), A(N);
  REP(i, 0, N) { cin >> X[i]; }
  REP(i, 1, N) { A[i] = X[i] - X[i - 1]; }
  A[0] = X[0] + L - X[N - 1];

  LL ans = 0;
  DUMP(A);
  REP(del, 1, N) {
    // VEC<LL> line(N - 1);
    // int index = 0;
    // int start = 0;
    // for (int i = del - 1; i < N;) {
    //   line[index] = A[i];
    //   if(i==0)start=i;
    //   --i;
    //   if (i < 0) i += N;
    // }
    LL leftsum = 0, rightsum = 0;
    LL mul = N - 1;
    REP(i, 0, del) {
      rightsum += (mul - 1) * A[i];
      leftsum += mul * A[i];
      DUMP("  ",leftsum, rightsum, mul);
      mul -= 2;
    }
    mul = N - 1;
    for(int i = N-1;i>0;--i){
      leftsum += (mul - 1) * A[i];
      rightsum += mul * A[i];
      DUMP("  ",leftsum, rightsum, mul);
      mul -= 2;
    }
    DUMP(del, leftsum, rightsum);
    ans=max({ans, leftsum, rightsum});
  }
  cout<<ans<<endl;

  return 0;
}
