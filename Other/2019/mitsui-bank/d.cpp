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

void show(VEC<VEC<int>> &a) {
  REP(i, 0, a.size()) {
    REP(j, 0, a[i].size()) { cerr << a[i][j] << " "; }
    cerr << endl;
  }
  cerr << endl;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  VEC<int> V(N);
  REP(i, 0, N) { V[i] = S[i] - '0'; }
  // DUMP(V);
  int dig = 10;
  auto cs = VEC<VEC<int>>(N, VEC<int>(dig, 0));

  cs[0][V[0]]++;
  REP(i, 1, N) {
    cs[i][V[i]]++;
    REP(j, 0, dig) { cs[i][j] += cs[i - 1][j]; }
  }
  // DUMP("HI");
  // show(cs);

  set<int> pattern;
  REP(i, 1, N - 1) {
    REP(dl, 0, dig) {
      if (cs[i - 1][dl] > 0) {
        REP(dr, 0, dig) {
          if(cs[N-1][dr]-cs[i][dr]>0){
            pattern.insert(dl*100+V[i]*10+dr);
          }
        }
      }
    }
  }
  cout<<pattern.size()<<endl;

  return 0;
}
