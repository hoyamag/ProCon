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
VEC<int> x;
int n, m;
bool func(int v) {
  int pos = x[0];
  int cnt = 1;
  REP(i, 1, m) {
    if (x[i] > pos + v) {
      ++cnt;
      pos = x[i];
    }
  }
  return cnt <= n;
}
int ans(int v) {
  int pos = x[0];
  int cnt = 1;
  LL a = 0;
  REP(i, 1, m) {
    if (x[i] > pos + v) {
      ++cnt;
      pos = x[i];
    } else {
      a += (x[i] - x[i-1]);
    }
    DUMP(a);
  }
  return a;
}

int main() {
  cin >> n >> m;
  x = VEC<int>(m);
  REP(i, 0, m) {
    cin >> x[i];
    x[i] += 1e5;
  }
  sort(ALL(x));
  DUMP(x);
  int ok = x[n - 1];
  int ng = 0;
  while (ok - ng > 1) {
    DUMP(ng, ok);
    int mid = (ok + ng) / 2;
    if (func(mid)) {
      ok = mid;
    } else
      ng = mid;
  }
  DUMP(ng, ok);
  DUMP(func(ng), func(ok));
  cout<<ans(ok);

  return 0;
}
