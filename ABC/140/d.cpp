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

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  N = S.length();
  int point=0;
  int optimal = N-1;
  REP(i,0,N-1){
    if(S[i]==S[i+1])point++;
  }
  int plus=2*K;
  cout<<min(optimal, point+plus)<<endl;
  // VEC<int> C;
  // int cnt = 1;
  // C.push_back(0);
  // REP(i, 0, N - 1) {
  //   if (S[i] != S[i + 1]) {
  //     C.push_back(cnt);
  //     cnt = 1;
  //   } else {
  //     cnt++;
  //   }
  // }
  // C.push_back(cnt);
  // DUMP(C);
  // int m = C.size();
  // int mid = m / 2;
  // LL sum = 0;
  // REP(i, 0, K) {
  //   if (mid - 1 >= 0) sum += C[mid - 1];
  //   if (mid + 1 < C.size()) sum += C[mid + 1];
  // }

  return 0;
}
