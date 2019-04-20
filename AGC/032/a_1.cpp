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
int N;
VEC<int> A, B;

VEC<int> rm(VEC<int> &a, int k) {
  VEC<int> ret(a.size() - 1);
  REP(i, 0, a.size() - 1) {
    if (i >= k) {
      ret[i] = a[i + 1];
    } else {
      ret[i] = a[i];
    }
  }
  return ret;
}
list<int> ans;
int dfs(VEC<int> &a) {
  // DUMP(a);
  int n = a.size();
  if (a.size() == 0) {
    return 1;
  }
  REP(i, 0, n) {
    if (a[i] == i+1) {
      auto t = rm(a, i);
      // DUMP("t", t);
      if (dfs(t)) {
        ans.push_back(i+1);
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cin >> N;
  B=VEC<int>(N);
  
  REP(i, 0, N) cin >> B[i];
  if (B[0] != 1) {
    cout << -1 << endl;
    return 0;
  }
  if (dfs(B)) {
    for (auto v : ans) {
      cout << v << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
