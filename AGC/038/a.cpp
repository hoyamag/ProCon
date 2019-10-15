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
int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  auto M = MATINIT(int, H, W, 0);
  auto invalid = [&]() -> bool {
    REP(i, 0, H) {
      int c = 0;
      REP(j, 0, W) {
        if (M[i][j]) c++;
      }
      if (c != A && W - c != A) return 1;
    }
    REP(j, 0, W) {
      int c = 0;
      REP(i, 0, H) {
        if (M[i][j]) c++;
      }
      if (c != B && H - c != B) return 1;
    }
    return 0;
  };
  if (A > W / 2 || B > H / 2) {
    cout << "No" << endl;
    return 0;
  }
  if (A == 0 || B == 0) {
    if (A == 0) {
      REP(j, 0, W) {
        REP(i, 0, B) { M[i][j] = 0; }
        REP(i, B, H) { M[i][j] = 1; }
      }
    } else {
      REP(i, 0, H) {
        REP(j, 0, A) { M[i][j] = 0; }
        REP(j, A, W) { M[i][j] = 1; }
      }
    }
    if (invalid()) {
      cout << "No" << endl;
      return 0;
    }
    REP(i, 0, H) {
      REP(j, 0, W) { cout << M[i][j]; }
      cout << '\n';
    }
    return 0;
  }
  if (H * A != W * B) {
    cout << "No" << endl;
    return 0;
  }
  if (A < B) {
    REP(i, 0, H) {
      REP(j, 0, A) {
        int h = i;
        int w = (i + j) % W;
        M[h][w] = 1;
      }
    }
  } else {
    REP(j, 0, W) {
      REP(i, 0, B) {
        int h = (i+j)%H;
        int w = j;
        M[h][w] = 1;
      }
    }
  }
  // DUMP(M);
  if (invalid()) {
    cout << "No" << endl;
    return 0;
  }
  REP(i, 0, H) {
    REP(j, 0, W) { cout << M[i][j]; }
    cout << '\n';
  }

  return 0;
}
