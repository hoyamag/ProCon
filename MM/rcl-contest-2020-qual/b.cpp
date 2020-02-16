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
  for (auto v : vec) os << setw(4) << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, list<T> &vec) {
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
template <typename T>
ostream &operator<<(ostream &os, VEC<VEC<T>> mat) {
  for (auto v : mat) os << v << endl;

  return os;
}
std::mt19937 MT(8);

int randInRange(int minimum, int limit) {
  return minimum + MT() % (limit - minimum);
}

enum DIR { U = 0, L, D, R };
struct Grid {
  int h, w;
};
struct Operation {
  int h, w;
  DIR dir;
};
int N, M;
const int RED = 0;
const int BLUE = 1;
const int GREEN = 2;
const int YELLOW = 3;

const int PLEN = 5;
VEC<VEC<int>> A, B;
VEC<Grid> Begin;
list<Operation> Ans;

char DirChar(DIR a) {
  if (a == DIR::U) {
    return 'U';
  }
  if (a == DIR::L) {
    return 'L';
  }
  if (a == DIR::D) {
    return 'D';
  }
  return 'R';
}
ostream &operator<<(ostream &os, const Operation a) {
  os << a.h << " " << a.w << " " << DirChar(a.dir);
  return os;
}
// void PushNewsToBegin(Operation a) {
// }
void Paint5(Operation a) {
  int h = a.h;
  int w = a.w;
  DIR d = a.dir;
  int color = B[h][w];
  if (d == DIR::U) {
    REP(i, 1, PLEN + 1) {
      if (h - i >= 0) {
        Begin.push_back({h - i, w});
        B[h - i][w] = color;
      }
    }
  } else if (d == DIR::L) {
    REP(i, 1, PLEN + 1) {
      if (w - i >= 0) {
        Begin.push_back({h, w - 1});
        B[h][w - i] = color;
      }
    }

  } else if (d == DIR::D) {
    REP(i, 1, PLEN + 1) {
      if (h + i < N) {
        Begin.push_back({h + i, w});
        B[h + i][w] = color;
      }
    }
  } else {
    REP(i, 1, PLEN + 1) {
      if (w + i < N) {
        Begin.push_back({h, w + 1});
        B[h][w + i] = color;
      }
    }
  }
}
void solve() {
  REP(i, 0, M) {
    int rand = randInRange(0, Begin.size());
    auto beg = Begin[rand];
    DIR dir = (DIR)randInRange(0, DIR::R + 1);
    Operation ope = {beg.h, beg.w, dir};
    Ans.push_back(ope);
    DUMP(ope);
    Paint5(ope);
    DUMP(B);
    // DUMP(Ans);
  }
}
int main() {
  // REP(i, 0, 100) cout << randInRange(0, 3);
  // REP(i, 0, 100) cout << DirChar((DIR)randInRange(0, 3));
  cin >> N >> M;
  A = VEC<VEC<int>>(N, VEC<int>(N, 0));
  B = VEC<VEC<int>>(N, VEC<int>(N, -1));
  REP(i, 0, N) {
    REP(j, 0, N) { cin >> A[i][j]; }
  }
  B[0][0] = RED;
  B[0][N - 1] = BLUE;
  B[N - 1][0] = GREEN;
  B[N - 1][N - 1] = YELLOW;
  Begin.push_back({0, 0});
  Begin.push_back({0, N - 1});
  Begin.push_back({N - 1, 0});
  Begin.push_back({N - 1, N - 1});

  solve();

  // REP(i, 0, M) { cout << -1 << endl; }
  for (auto v : Ans) {
    cout << v.h << " " << v.w << " " << DirChar(v.dir) << endl;
  }

  return 0;
}
