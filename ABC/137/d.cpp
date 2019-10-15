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
  int N, M;
  cin >> N >> M;
  VEC<pair<int, int>> B(N);
  REP(i, 0, N) { cin >> B[i].first >> B[i].second; }
  auto comp = [](pair<int, int> a, pair<int, int> b) -> bool {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
  };
  sort(ALL(B), comp);
  // DUMP(B);
  priority_queue<int> pq;
  int j = 0;
  LL cnt = 0;
  REP(i, 1, M + 1) {
    // DUMP(i, j);
    while (j < N && B[j].first <= i) {
      // DUMP(j);
      pq.push(B[j].second);
      j++;
    }
    // DUMP("HI");
    if (!pq.empty()) {
      // DUMP(pq.top());
      cnt += pq.top();
      pq.pop();
    }
  }
  cout << cnt << endl;

  return 0;
}
