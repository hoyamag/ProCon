#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
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
  LL maxSize = 100;
  VEC<LL> x(N), y(N), hi(N);
  REP(i, 0, N) { cin >> x[i] >> y[i] >> hi[i]; }
  for (LL h = 0; h <= maxSize; ++h) {
    for (LL w = 0; w <= maxSize; ++w) {
      LL height;
      REP(i, 0, N) {
        if (hi[i] > 0)
          height = (LL)(abs(x[i] - w) + abs(y[i] - h)) + hi[i];
      }

      bool valid = true;

      REP(t, 0, N) {
        LL ch = (LL)(abs(x[t] - w) + abs(y[t] - h)) + hi[t];
        if (ch != height || ch <= 0) {
          valid = false;
          break;
        }
      }
      if (valid) {
        REP(t, 0, N) {
          LL ch = max(height - (LL)(abs(x[t] - w) + abs(y[t] - h)), 0LL);
          if (ch != hi[t]) {
            valid = false;
            break;
          }
          if (valid) {
            cout << w << " " << h << " " << height << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
