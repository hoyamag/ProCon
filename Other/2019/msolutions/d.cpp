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
  int u, v, w;
};
struct node {
  int index, w;
};
VEC<list<int>> G;

int main() {
  int N;
  cin >> N;
  G = VEC<list<int>>(N);
  VEC<int> D(N);
  REP(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  REP(i, 0, N) { cin >> D[i]; }
  sort(ALL(D));
  LL sum = 0;
  REP(i, 0, N - 1) { sum += D[i]; }
  cout << sum << endl;

  reverse(ALL(D));
  queue<int> q;
  VEC<int> ans(N, 0);
  q.push(0);
  int index = 0;
  VEC<bool> used(N, 0);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    used[node]=true;
    ans[node] = D[index];
    index++;
    for (auto v : G[node]) {
      if (used[v]) continue;
      q.push(v);
    }
  }
  REP(i,0,N){
    cout<<ans[i]<<" ";
  }
  cout<<endl;

  return 0;
}
