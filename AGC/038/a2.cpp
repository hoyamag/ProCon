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
void dumpmat(VEC<VEC<int>> &m) {
  REP(i, 0, m.size()) {
    REP(j, 0, m[i].size()) { cout << m[i][j]; }
    cout << "\n";
  }
}
int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  auto M = MATINIT(int, max(H, W), max(H, W), 0);
  bool sw = 0;
  auto myswap = [&]() {
    REP(i, 0, H) {
      REP(j, 0, W) { swap(M[i][j], M[j][i]); }
    }
    swap(H, W);
    swap(A, B);
  };
  auto show = [&]() {
    if (sw) {
      myswap();
    }
    REP(i, 0, H) {
      REP(j, 0, W) { cout << M[i][j]; }
      cout << '\n';
    }
  };
  //   auto show_noswap = [&]() {
  //     REP(i, 0, H) {
  //       REP(j, 0, W) { cout << M[i][j]; }
  //       cout << '\n';
  //     }
  //   };
  auto check_invalid = [&]() -> bool {
    REP(i, 0, H) {
      int c = 0;
      REP(j, 0, W) {
        if (M[i][j]) c++;
      }
      if (min(c, W - c) != A) {
        show();
        return 1;
      }
    }
    REP(j, 0, W) {
      int c = 0;
      REP(i, 0, H) {
        if (M[i][j]) c++;
      }
      if (min(c, H - c) != B) {
        show();
        return 1;
      }
    }
    return 0;
  };

  if (A > B) {
    sw = 1;
    myswap();
  }
  if (A == 0 && B == 0) {
    show();
    return 0;
  }
  if (A == 0) {
    REP(i, 0, B) {
      REP(j, 0, W) { M[i][j] = 1; }
    }
    if (check_invalid()) {
      cout << "No" << endl;
      return 0;
    }
    show();
    return 0;
  }
  REP(i, 0, H) {
    REP(j, 0, A) {
      int h = i;
      int w = (i * A + j) % W;
      M[h][w] = 1;
    }
    // puts("");
    // show_noswap();
  }
  if (check_invalid()) {
    REP(i, 0, H) {
      REP(j, 0, A) {
        int h = i;
        int w = (i * A + j) % W;
        M[h][w] = 1;
      }
      // puts("");
      // show_noswap();
      if (check_invalid()) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  show();
  return 0;
}
