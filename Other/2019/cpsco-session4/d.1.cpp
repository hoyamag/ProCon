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
  int N, K;
  cin >> N >> K;
  VEC<int> A(N + 1, -1);
  REP(i, 0, N) cin >> A[i];
  priority_queue<int> q;
  int cnt = 1;
  REP(i, 1, N + 1) {
    if (A[i] != A[i - 1]) {
      // DUMP(cnt);
      q.push(cnt);
      cnt = 0;
    }
    ++cnt;
  }
  int mi = INT32_MAX;
  priority_queue<int> orig = q;

  REP(i, 0, K) {
    int s = q.top();
    q.pop();
    if (s % 2 == 0) {
      q.push(s / 2);
      q.push(s / 2 - 1);
    } else {
      q.push(s / 2);
      q.push(s / 2);
    }
    // DUMP(s, s / 2, (s + 1) / 2);
  }
  q.push(1);
  mi = q.top();
  // DUMP("mi", mi);

  q = orig;
  // DUMP(q.top());
  REP(i, 0, K - 2) {
    int s = q.top();
    q.pop();
    if (s % 2 == 0) {
      q.push(s / 2);
      q.push(s / 2 - 1);
    } else {
      q.push(s / 2);
      q.push(s / 2);
    }
    // DUMP(s, s / 2, (s + 1) / 2);
  }
  if (K >= 2) {
    int s = q.top();
    q.pop();
    if (s % 3 == 0) {
      q.push(s / 3 - 1);
      q.push(s / 3);
      q.push(s / 3);
    } else {
      q.push(s / 3);
      q.push(s / 3);
      q.push((s + 2) / 3 - 1);
    }
    q.push(1);
    // DUMP(q.top());
    mi = min(mi, q.top());
  }

  cout << mi << endl;

  return 0;
}
