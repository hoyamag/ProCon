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
const int N = 1e4;
const int M = 1e4;
list<pair<int, int>> G[N + 1];

int answer = 0;
VEC<int> minpath(N, 1e9);

int main() {
  int n, m;
  cin >> n >> m;
  REP(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    int cost, node;
    tie(cost, node) = pq.top();
    pq.pop();
    if (cost < minpath[node]) {
      minpath[node] = cost;
    }
    if (node == n - 1 && cost <= minpath[node]) {
      answer++;
    }
    if (cost >= minpath[n - 1]) continue;
    for (auto v : G[node]) {
      pq.push({cost + v.second, v.first});
    }
  }
  cout << answer << endl;

  return 0;
}
