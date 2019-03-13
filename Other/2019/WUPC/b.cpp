#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, set<T> &s) {
  os << "{";
  for (auto p : s)
    os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m)
    os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
int Num(int n) {
  // Num to under 5;
  int ans = 0;
  if (n <= 5)
    ans = 0;
  else if (n <= 7)
    ans = 1;
  else if (n <= 8)
    ans = 2;
  else if (n <= 9)
    ans = 3;
  return ans;
}

int main() {
  int H, W;
  cin >> H >> W;
  if (H > W)
    swap(H, W);
  int A[H][W];
  VEC<int> dig(10, 0);
  REP(i, 0, H) {
    REP(j, 0, W) {
      cin >> A[i][j];
      dig[A[i][j]]++;
    }
  }
  // DUMP(dig);
  if (dig[0] == H * W) {
    cout << "Yes 0" << endl;
  } else if (dig[5] == 0) {
    cout << "No" << endl;
  } else if (H == 1 && W > 1) {
    int ma = 0;
    VEC<int> dig2(dig);
    int cnt = 0;
    int ans = 1 << 30;
    REP(i, 0, W) {
      int v = A[0][i];
      dig2[v]--;
      ma = max(ma, Num(v));
      // DUMP(v, ma, cnt);
      if (v == 5) {
        int left = ma;
        int right = 0;
        REP(i, 0, 10) {
          if (dig2[i])
            right = max(right, Num(i));
        }

        cnt = left + right + 1;
        ans=min(ans,cnt);
      }
    }
    cout << "Yes " << ans << endl;

  } else {
    int ans = 1;
    if (dig[9] > 0)
      ans = 4;
    else if (dig[8] > 0)
      ans = 3;
    else if (dig[6] > 0 || dig[7] > 0)
      ans = 2;

    cout << "Yes " << ans << endl;
  }

  return 0;
}
