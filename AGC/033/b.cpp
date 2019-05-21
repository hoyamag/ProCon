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
void show(VEC<VEC<int>> m) {
  REP(i, 0, m.size()) {
    REP(j, 0, m[i].size()) { cerr << m[i][j] << " "; }
    cerr << endl;
  }
}

int main() {
  int H, W, N, Sr, Sc;
  cin >> H >> W >> N >> Sr >> Sc;
  string S, T;
  cin >> S >> T;
  auto matS = MATINIT(int, 4, N, 0);
  auto matT = MATINIT(int, 4, N, 0);
  int U = 0, D = 1, L = 2, R = 3;
  VEC<char> dir = {'U', 'D', 'L', 'R'};

  REP(i, 0, R + 1) {
    REP(j, 0, N) {
      if (S[j] == dir[i]) {
        matS[i][j]++;
      }
      if (T[j] == dir[i]) {
        matT[i][j]++;
      }
    }
  }
  show(matS);
  DUMP();
  show(matT);
  DUMP();

  REP(i, 0, R + 1) {
    REP(j, 1, N) {
      matS[i][j] += matS[i][j - 1];
      matT[i][j] += matT[i][j - 1];
    }
  }
  show(matS);
  DUMP();
  show(matT);
  DUMP();

  REP(j, 1, N) {
    // matS[U][j] = min(matS[U][j], Sr - 1);
    // matS[D][j] = min(matS[D][j], H - Sr);
    // matS[L][j] = min(matS[L][j], Sc - 1);
    // matS[R][j] = min(matS[R][j], W - Sc);

    matT[U][j] = min(matT[U][j], Sr - 1);
    matT[D][j] = min(matT[D][j], H - Sr);
    matT[L][j] = min(matT[L][j], Sc - 1);
    matT[R][j] = min(matT[R][j], W - Sc);
  }
  show(matS);
  DUMP();
  show(matT);
  DUMP();

  REP(j, 0, N) {
    DUMP(j);
    if (matS[U][j] - matT[D][j] > Sr) {
      DUMP('U');
      cout << "NO" << endl;
      return 0;
    }
    if (matS[D][j] - matT[U][j] > H - Sr) {
      DUMP('D');
      cout << "NO" << endl;
      return 0;
    }
    if (matS[L][j] - matT[R][j] > Sc) {
      DUMP('L');
      cout << "NO" << endl;
      return 0;
    }
    if (matS[R][j] - matT[L][j] > W - Sc) {
      DUMP('R');
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
