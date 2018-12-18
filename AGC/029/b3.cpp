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
#define ull unsigned long long
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1n(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;

int main() {
  int n;
  cin >> n;
  VEC<int> a(n);
  REP(i, 0, n) cin >> a[i];
  sort(ALL(a));
  int ans = 0;
  for (int nibeki = 1 << 30; nibeki > 1; nibeki >>= 1) {
    // DUMP(a);
    // DUMP("***", nibeki);
    for (int left = 0, right = n - 1; left < right;) {
      if (a[left] < 1) {
        ++left;
      } else if (a[right] < 1) {
        --right;
      } else {
        int target = nibeki - a[right];

        if (target == a[left]) {
          a[left] = a[right] = -1;
          --right;
          ++left;
          ++ans;
        } else if (target < a[left]) {
          --right;
        } else if (target > a[left])
          ++left;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
