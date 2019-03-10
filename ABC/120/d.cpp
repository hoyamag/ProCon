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
bool has(map<int, int> m, int key) { return m.find(key) != m.end(); }
const int inf = 1 << 30;
int main() {
  int N, M;
  cin >> N >> M;
  VEC<int> A(M), B(M);
  REP(i, 0, M) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  map<int, int> renketu;  // node number to connected minimum edge
  reverse(ALL(A));
  reverse(ALL(B));
  LL huben = N * (N - 1) / 2;
  VEC<LL> ansreverse(M, huben);
  VEC<LL> connectedSize(M, 1);  // edge num to connected graph size
  REP(edge, 0, M) {
    int left = A[edge];
    int right = B[edge];
    int curL = inf;
    int curR = inf;
    LL curSizeL = 1;
    LL curSizeR = 1;
    if (has(renketu, left)) {
      curL = renketu[left];
      curSizeL = connectedSize[left];
    }
    if (has(renketu, right)) {
      curR = renketu[right];
      curSizeR = connectedSize[right];
    }
    if (curL != curR || (curL== inf && curR==inf)) {
      int cur = min(curL, curR);
      renketu[left] = renketu[right] = min(cur, edge);
      connectedSize[left] = connectedSize[right] = curSizeL + curSizeR;

      DUMP(edge, left, right, curL, curR, curSizeL, curSizeR);
      huben -= curSizeL * curSizeR;
    }

    ansreverse[edge] = huben;
  }
  reverse(ALL(ansreverse));
  DUMP(ansreverse);
  // for (auto v : ansreverse) {
  //   cout << v << endl;
  // }
  REP(i,1,M){
      cout<<ansreverse[i]<<endl;
  }
  cout<<N*(N-1)/2<<endl;
  return 0;
}
