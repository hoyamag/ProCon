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
void show(priority_queue<LL, vector<LL>, greater<LL>> pq) {
  cerr << "{ ";
  while (!pq.empty()) {
    LL a = pq.top();
    pq.pop();
    cerr << a << ", ";
  }
  cerr << "}" << endl;
}

int main() {
  int N;
  cin >> N;
  VEC<LL> A(N);
  LL inf = 1e9 + 3;
  VEC<LL> tmp(N, inf);
  REP(i, 0, N) { cin >> A[i]; }
  priority_queue<LL, vector<LL>, greater<LL>> pq;
    LL ma = -1;
  for (int i = N - 1; i >= 0; i--) {
    // DUMP(i, A[i], ma);
    bool pushed = 0;
    int index = 0;
    while (!pq.empty()) {
      // DUMP("H");
      // if (A[i] >= ma) break;
      auto top = pq.top();
      if (A[i] < top) {
        pushed = 1;
        pq.pop();
        ma = max(ma, A[i]);
        pq.push(A[i]);
        break;
      }
      pq.pop();
      tmp[index] = top;
      index++;
    }
    // show(pq);
    if (!pushed) {
      ma = max(ma, A[i]);
      pq.push(A[i]);
    }
    // show(pq);
    REP(i, 0, index) { pq.push(tmp[i]); }
    // show(pq);
  }
  cout << pq.size() << endl;

  return 0;
}
