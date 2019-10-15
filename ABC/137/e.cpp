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
struct edge {
  int from, to, cost;
};

const int MAX_V = 2501;
const int MAX_E = 5001;
const int INF = 1 << 30;
edge es[MAX_E];
set<int> inf_list;

int d[MAX_V];
int V, E;

// bool shortest_path(int s) {
//   for (int i = 0; i < V; i++) d[i] = INF;
//   d[s] = 0;
//   int cnt = 0;
//   while (1) {
//     bool update = false;
//     for (int i = 0; i < E; i++) {
//       edge e = es[i];
//       if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
//         d[e.to] = d[e.from] + e.cost;
//         update = true;
//       }
//     }
//     if (!update) break;
//     cnt++;
//     if (cnt > MAX_V) {
//       return 0;
//     }
//   }
//   return 1;
// }
bool shortest_path(int s) {
  for (int i = 0; i < V; i++) d[i] = INF;
  d[s] = 0;
  int cnt = 0;
  bool ret = 0;
  while (1) {
    bool update = false;
    cnt++;
    for (int i = 0; i < E; i++) {
      edge e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
        if (cnt >= MAX_V) {
          inf_list.insert(e.to);
        }
      }
    }
    if (!update) break;
    if (cnt >= MAX_V) {
      ret = 1;
    }
    if (cnt > 2 * MAX_V) {
      return ret;
    }
  }
  return ret;
}

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  V = N;
  E = M;
  REP(i, 0, M) {
    int f, t, c;
    cin >> f >> t >> c;
    f--;
    t--;
    c -= P;
    es[i] = {f, t, -c};
  }
  shortest_path(0);
  if (inf_list.count(N - 1)) {
    cout << -1 << endl;
    return 0;
  }
  cout << max({0, -d[N - 1]}) << endl;
  // REP(i, 0, N) { cerr << -d[i] << endl; }

  return 0;
}
