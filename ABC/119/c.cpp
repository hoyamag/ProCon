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
VEC<int> L;
int AMAX = 1000;
// int cost(int obj, VEC<int> take) {
//   int inf = 1 << 31;
//   VEC<LL> dp(AMAX + 1, inf);
//   int N = take.size();

//   REP(i, 0, N) { dp[L[i]] = 0; }
//   REP(i, 0, N) {
//     LL m = min(dp[i + 1], dp[i] + 1);
//     REP(j, 1, i+1) { m = min(m, dp[j] + dp[i - j + 1] + 10); }
//   }
// }
int bitcount(int bit) {
  int sum = 0;

  REP(i, 0, 32) {
    if (bit & (1 << i)) {
      ++sum;
    }
  }
  return sum;
}
const int inf = 1 << 30;
LL cost(int obj, VEC<int> take) {
  DUMP("cost", obj, take);
  int N = take.size();
  int ketaLIM = 1 << N;
  LL sumMax = 0;
  REP(i, 0, N) { sumMax += take[i]; }
  auto dp = MATINIT(LL, sumMax + 1, ketaLIM, inf);
  VEC<LL> ans(sumMax + 1, inf);

  REP(bit, 0, ketaLIM) { dp[0][bit] = 0; }
  DUMP("N", N, ketaLIM, sumMax);

  REP(bit, 1, ketaLIM) {
    DUMP("L88", bit);
    LL sum = 0;
    int length = 0;
    int cnt = 0;
    REP(i, 0, N) {
      if (bit & (1 << i)) {
        DUMP("take[i]", take[i]);
        length += take[i];
        ++cnt;
      }
    }
    sum += (cnt - 1) * 10;
    DUMP("bit", bit, "cnt", cnt, "sum", sum, "length", length);
    dp[length][bit] = min(dp[length][bit], sum);
    ans[length] = min(ans[length], sum);
  }
  LL answer = inf;
  REP(l, 0, sumMax + 1) { answer = min(answer, ans[l] + (LL)abs(obj - l)); }
  DUMP(ans);
  return answer;
}

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  L = VEC<int>(N);
  REP(i, 0, N) cin >> L[i];
  int lim = 1 << 8;
  LL answer = inf;
  REP(bitA, 0, lim) {
    VEC<int> setA, setBC;

    REP(i, 0, N) {
      if (bitA & (1 << i)) {
        setA.push_back(L[i]);
      } else {
        setBC.push_back(L[i]);
      }
    }
    if (setA.size() == 0 || setBC.size() < 2) continue;
    int sizeBC = setBC.size();
    int limBC = 1 << sizeBC;
    REP(bitB, 0, limBC) {
      VEC<int> setB, setC;
      REP(i, 0, sizeBC) {
        if (bitB & (1 << i)) {
          setB.push_back(setBC[i]);
        } else {
          setC.push_back(setBC[i]);
        }
      }
      if (setB.size() == 0 || setC.size() == 0) continue;
      auto ansA = cost(A, setA);
      auto ansB = cost(B, setB);
      auto ansC = cost(C, setC);
      answer = min({answer, ansA, ansB, ansC});
      DUMP(setA, setB, setC, answer);
    }
  }
  cout << answer << endl;

  return 0;
}
