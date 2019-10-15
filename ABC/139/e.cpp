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
VEC<VEC<int>> G;

int main() {
  int N;
  cin >> N;
  VEC<queue<int>> TO(N);
  REP(i, 0, N) {
    REP(j, 0, N - 1) {
      int a;
      scanf("%d", &a);
      a--;
      TO[i].push(a);
    }
  }
  LL cnt = 0;
  LL sum = N * (N - 1);
  LL days = 0;
  int prev = cnt;
  // これは通らないけど変更点をqueueに入れるように舐め方を変えると通るらしい
  while (cnt < sum && days < sum + 2) {
    VEC<int> done(N, 0);
    REP(i, 0, N) {
      if (TO[i].size() > 0) {
        int p = TO[i].front();
        if (TO[p].size() > 0) {
          if (i == TO[p].front()) {
            cnt++;
            done[i] = 1;
            done[p] = 1;
            // DUMP(days, cnt, i + 1, p + 1);
          }
        }
      }
    }
    days++;
    if (cnt == prev) {
      cout << -1 << endl;
      return 0;
    } else {
      prev = cnt;
    }
    REP(i, 0, N) {
      if (done[i]) TO[i].pop();
    }
  }
  if (days == sum + 2) {
    cout << -1 << endl;
    return 0;
  }
  printf("%lld\n", days);

  return 0;
}
