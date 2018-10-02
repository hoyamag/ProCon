#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using LL = long long;
using ULL = unsigned long long;
using namespace std;
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
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  int n;
  std::cin >> n;
  VEC<int> v(n);
  std::map<int, int> even, odd;
  REP(i, 0, n) {
    std::cin >> v[i];
    if (i % 2 == 0) {
      even[v[i]]++;
    } else {
      odd[v[i]]++;
    }
  }
  int evenMax = 0;
  int oddMax = 0;
  int evenMax2 = 0, oddMax2 = 0;
  int evenNum, oddNum;
  REP(i, 0, n) {
    if (i % 2 == 0) {
      if (even[v[i]] > evenMax) {
        evenMax2 = evenMax;
        evenMax = even[v[i]];
        evenNum = v[i];
      }
    } else {
      if (odd[v[i]] > oddMax) {
        oddMax2 = oddMax;
        oddMax = odd[v[i]];
        oddNum = v[i];
      }
    }
  }
  DUMP(evenNum, oddNum);
  if (evenNum == oddNum) {
    DUMP(n, evenMax, evenMax2, oddMax, oddMax2);
    std::cout << std::min(n - evenMax - oddMax2, n - evenMax2 - oddMax)
              << std::endl;

  } else {
    std::cout << n - evenMax - oddMax << std::endl;
  }

  return 0;
}
