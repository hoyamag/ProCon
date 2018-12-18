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
// 1110100011010100101001010001000000000000
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
  int n, k;
  cin >> n >> k;
  VEC<LL> a(n);
  REP(i, 0, n) cin >> a[i];
  LL siz = n * (n + 1) / 2;
  VEC<LL> sum(siz, 0);
  int cnt = 0;
  REP(i, 0, n) {
    LL s = 0;
    REP(j, i, n) {
      s += a[j];
      sum[cnt] = s;
      ++cnt;
    }
  }
  //DUMP(siz, sum);
  sort(ALL(sum));
  reverse(ALL(sum));

  VEC<LL> ans(k, 0);
  LL lim = 0b10000000000000000000000000000000000000000;
  //DUMP(lim);
  for (LL i = lim; i > 0; i = (i >> 1)) {
    int count = 0;
    REP(j, 0, siz) {
      if ((sum[j] & i) > 0) {
        ++count;
      }
    }
    //DUMP(i, "count", count);
    if (count == k) {
      // ans
      break;

    } else if (count > k) {
      // continue, cand limited
      //DUMP("limit");
      auto newlast = sum.begin();
      REP(j, 0, siz) {
        if ((sum[j] & i) <= 0) {
          break;
        }
        ++newlast;
      }
      sum = VEC<LL>(sum.begin(), newlast);
      //DUMP("    ", sum);
      siz = sum.size();

    } else {
      // continue, cand no info
      //DUMP("no info");
      REP(j, 0, siz) {
        if ((sum[j] & i) > 0) {
          sum[j] -= i;
        }
      }
    }
    sort(ALL(sum), greater<LL>());
    //DUMP(i, count, sum);
  }

  REP(j, 0, k) { ans[j] = sum[j]; }
  LL z = ans[0];
  REP(i, 1, k) { z = z & ans[i]; }
  cout << z << endl;

  return 0;
}
