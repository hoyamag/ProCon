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
  int n;
  cin >> n;
  VEC<LL> a(n), b(n);
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) cin >> b[i];

  LL lsum = 0;
  int lnum = 0;
  VEC<LL> sup;
  REP(i, 0, n) {
    int d = a[i] - b[i];
    if (d > 0) {
      sup.push_back(d);
    } else if (d < 0) {
      lsum += d;
      ++lnum;
    }
  }
  sort(ALL(sup));
  LL ans = lnum;
  // DUMP(ans, lsum, sup);
  while (!sup.empty() && lsum < 0) {
    LL s = sup.back();
    sup.pop_back();
    lsum += s;
    ++ans;
    if (lsum >= 0) {
      break;
    }
  }
  // DUMP(ans, lsum, sup);
  if (lsum >= 0) cout << ans << endl;
  else cout<<-1<<endl;

  return 0;
}
