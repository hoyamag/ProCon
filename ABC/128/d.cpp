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

void showPq(priority_queue<LL, VEC<LL>, greater<LL>> pq) {
  while (pq.empty() == false) {
    cerr << pq.top() << ", ";
    pq.pop();
  }
  cerr << endl;
}

int main() {
  LL N, K;
  cin >> N >> K;
  VEC<LL> V(N);
  REP(i, 0, N) cin >> V[i];
  LL ma = 0;
  REP(a, 0, K + 1) {
    REP(b, 0, K - a + 1) {
      int size = N;
      int c = K - a - b;
      // DUMP("begin", a, b, c);
      priority_queue<LL, VEC<LL>, greater<LL>> pq;
      LL sum = 0;
      REP(i, 0, a) {
        if (size <= 0) break;
        // DUMP("a   ", V[i]);
        pq.push(V[i]);
        sum += V[i];
        size--;
      }
      REP(i, 0, b) {
        if (size <= 0) break;
        // DUMP("b   ", V[N - i - 1]);
        pq.push(V[N - i - 1]);
        sum += V[N - i - 1];
        size--;
      }
      // showPq(pq);
      REP(i, 0, c) {
        if (pq.empty()) break;
        // DUMP("pq.top   ", pq.top());
        if (pq.top() >= 0) break;
        sum -= pq.top();
        pq.pop();
        size++;
      }
      // DUMP(a, b, c, sum);
      ma = max(ma, sum);
    }
  }
  cout << ma << endl;

  return 0;
}
