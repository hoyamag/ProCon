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
const LL N = 50;
VEC<LL> total(N + 1, 0);
VEC<LL> paty(N + 1, 0);

LL num_paty(LL level, LL run) {
  if(run==0)return 0;
  if (level == 0) {
    if (run >= 1) {
      return 1LL;
    } else
      return 0LL;
  } else {
    if (run <= 1) {
      return 0;
    } else if (run < total[level] / 2 + 1)
      return num_paty(level - 1, run - 1);
    else if (run == total[level] / 2 + 1)
      return paty[level - 1] + 1;
    else if (run < total[level])
      return num_paty(level - 1, run - total[level] / 2 - 1) + paty[level - 1] +
             1;
    else
      return paty[level];
  }
}

int main() {
  LL n, x;
  cin >> n >> x;
  LL num = 1;
  LL npaty = 1;
  REPC(i, 0, N) {
    total[i] = num;
    num = 2 * num + 3;
    paty[i] = npaty;
    npaty = 2 * npaty + 1;
  }
  // DUMP(total);
  // DUMP(paty);
  cout << num_paty(n, x) << endl;

  return 0;
}
