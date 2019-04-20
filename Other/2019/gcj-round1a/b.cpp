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
const int C = 18;
int Night = 18;
int M = 100;
int solve() {
  VEC<int> b(C, 2);
  VEC<int> r(C);
  VEC<int> rem(C + 1, 0);
  int lb = 0;

  REP(ni, 0, Night) {
    REP(i, 0, C) { printf("%d ", b[i]); }
    puts("");
    fflush(stdout);

    int sum = 0;
    REP(i, 0, C) {
      scanf("%d", &r[i]);
      if (r[i] == -1) return -1;
      sum += r[i];
    }

    rem[b[0]] = sum % b[0];
    lb = max(lb, sum);

    if (b[0] < 18) {
      REP(i, 0, C) b[i]++;
    }
  }
  REP(gopher, lb, M + 1) {
    bool all = 1;
    REP(j, 2, C + 1) {
      if (gopher % j != rem[j]) {
        all = 0;
        break;
      }
    }
    if (all) {
      printf("%d\n", gopher);
      fflush(stdout);
      return 0;
    }
  }
  return 0;
}

int main() {
  // REP(i,2,19){
  //   DUMP(97%i);
  // }
  int T;
  cin >> T >> Night >> M;
  REP(i, 0, T) {
    if (solve() == -1) return 0;
  }

  return 0;
}
