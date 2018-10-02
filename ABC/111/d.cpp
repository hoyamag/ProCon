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
  int n;
  cin >> n;
  VEC<LL> X(n), Y(n);
  VEC<LL> dist(n);
  REP(i, 0, n) {
    cin >> X[i] >> Y[i];
    dist[i] = abs(X[i]) + abs(Y[i]);
  }
  bool even = 1;
  REP(i, 0, n) {
    if (dist[i] % 2 != 0) {
      even = false;
      break;
    }
  }
  bool odd = 1;
  REP(i, 0, n) {
    if (dist[i] % 2 != 1) {
      odd = false;
      break;
    }
  }
  if (even || odd) {
    int m = 40 - odd;
    VEC<int> d(m, 1);
    VEC<string> ans(n, "");
    REP(i, 0, n) {
      stringstream s;
      if (abs(X[i]) > 10 || abs(Y[i]) > 10) {
        REP(i, 0, m) cout << "L";
        cout << endl;
        continue;
      }
      REP(x, 0, abs(X[i])) {
        if (X[i] > 0)
          s << "R";
        else
          s << "L";
      }
      REP(y, 0, abs(Y[i])) s << (Y[i] > 0 ? "U" : "D");
      REP(y, abs(X[i])+abs(Y[i]), m) {
        s << "UD";
        ++y;
      }
      ans[i] = s.str();
    }

    cout << m << endl;
    REP(i, 0, m) {
      cout << d[i];
      if (i < m - 1)
        cout << " ";
    }
    cout << endl;
    REP(i, 0, n) { cout << ans[i] << endl; }
  } else {
    cout << -1 << endl;
  }

  return 0;
}
