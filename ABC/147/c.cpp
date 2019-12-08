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
set<int> f, u;
set<int> af, au;
VEC<VEC<pair<int, int>>> A;

void trueman(int n) {
  if (af.count(n) > 0) return;
  //DUMP("trueman", n);
  af.insert(n);
  REP(i, 0, A[n].size()) {
    //DUMP("A[n][i]", A[n][i]);
    if (A[n][i].second == 1) {
      //DUMP("  ", i);
      trueman(A[n][i].first);
    } else {
      au.insert(A[n][i].first);
    }
  }
}

int main() {
  int N;
  cin >> N;
  A = VEC<VEC<pair<int, int>>>(N, VEC<pair<int, int>>());
  REP(i, 0, N) {
    int a;
    cin >> a;
    A[i] = VEC<pair<int, int>>(a);
    REP(j, 0, a) {
      cin >> A[i][j].first >> A[i][j].second;
      A[i][j].first--;
    }
  }
  int lim = pow(2, N);
  int ans = 0;

  REP(bit, 0, lim) {
    f.clear();
    u.clear();
    int cnt = 0;
    REP(i, 0, N) {
      if ((bit >> i) & 1) {
        f.insert(i);
        cnt++;
      } else {
        u.insert(i);
      }
    }
    af.clear();
    au.clear();
    for (auto v : f) {
      trueman(v);
    }
    set<int> af_au;
    set<int> f_au;
    set_intersection(ALL(af), ALL(au), inserter(af_au, af_au.end()));
    set_intersection(ALL(f), ALL(au), inserter(f_au, f_au.end()));
    //DUMP(f, u);
    //DUMP(af, au);
    //DUMP(af_au);
    if (af_au.empty() && f_au.empty()) {
      //DUMP(ans, cnt);
      ans = max(ans, cnt);
      //DUMP("TRUE");
    } else {
      //DUMP("NOT");
    }
  }
  cout << ans << endl;

  return 0;
}
