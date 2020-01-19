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

int main() {
  int N;
  cin >> N;
  VEC<pair<LL, LL>> X(N);
  VEC<pair<LL, LL>> I(N);
  REP(i, 0, N) { cin >> X[i].first >> X[i].second; }
  REP(i, 0, N) {
    I[i].first = X[i].first - X[i].second;
    I[i].second = X[i].first + X[i].second;
  }
  auto compare = [](pair<LL, LL> a, pair<LL, LL> b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  };
  // I={{1,3},{0,3},{3,3},{2,3}};
  // DUMP(I);
  sort(ALL(I), compare);
  // DUMP(I);
  LL end = I[0].second;
  int cnt = 1;
  REP(i, 1, N) {
    if (I[i].first >= end) {
      cnt++;
      end = I[i].second;
    }
  }
  cout<<cnt<<endl;

  return 0;
}
