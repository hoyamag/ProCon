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
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  LL left = 1, right = 1e9;
  LL maxRange = right;
  cout << "? " << right << endl;
  string original;
  cin >> original;
  int cnt = 1;
  LL mid;
  string midEvenOdd;
  bool maxFlag = original == "even";
  while (abs(right - left) > 2) {
    ++cnt;
    mid = (left + right) / 2;
    mid += mid % 2 == 0 ? 1 : 0;
    DUMP(cnt, left, mid, right);
    cout << "? " << mid << endl;
    cin >> midEvenOdd;
    if (midEvenOdd == original) {
      right = mid;
    } else {
      left = mid;
    }
    maxFlag = (maxFlag && midEvenOdd == "odd");
  }
  mid = (left + right) / 2;
  DUMP(cnt, left, mid, right);
  if (maxFlag) {
    cout << "! " << maxRange << endl;
  } else {
    REP(i, left, right) {
      string s = (i % 2 == 0 ? "even" : "odd");
      if (s == original)
        cout << "! " << i << endl;
    }
  }
  return 0;
}
