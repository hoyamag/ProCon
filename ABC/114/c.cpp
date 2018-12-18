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
LL n;
VEC<int> box = {3, 5, 7};
int keta;
int siz = 3;
VEC<LL> cand(15, 0);
int cnt = 0;
void dfs(int th) {
  if (th == 0) {
    LL sum = 0;
    VEC<bool> f(10, 0);

    REP(i, 0, cand.size()) {

      sum += (LL)pow(10, i) * cand[i];
      f[(int)cand[i]] = 1;
    }
    if (f[3] && f[5] && f[7] && sum <= n) {
      ++cnt;
    }
    return;
  } else {
    REP(i, 0, siz) {
      LL tmp = cand[th - 1];
      cand[th - 1] = box[i];
      dfs(th - 1);
      cand[th - 1] = tmp;
    }
  }
}

int main() {
  cin >> n;
  keta = log10(n) + 1;
  //DUMP(keta);
  REP(i, 3, keta + 1) {
    cand = VEC<LL>(i, 0);
    dfs(i);
  }
  cout << cnt << endl;

  return 0;
}
