
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
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  LL N;
  cin >> N;
  LL lim = 100;
  VEC<LL> x(N), y(N), h(N);
  int base;
  REP(i, 0, N) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] > 0) base = i;
  }
  REPC(i, 0, lim) {
    REPC(j, 0, lim) {
      int height = abs(i - x[base]) + abs(j - y[base]) + h[base];
      bool ok = 1;
      REP(k, 0, N) {
        int sh = max(height - abs(i - x[k]) - abs(j - y[k]), 0LL);
        if (sh != h[k]) ok = 0;
      }
      if(ok){
          cout<<i<<" "<<j<<" "<<height<<endl;
      }
    }
  }
  return 0;
}
