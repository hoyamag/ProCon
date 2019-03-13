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
template <typename T> ostream &operator<<(ostream &os, set<T> &s) {
  os << "{";
  for (auto p : s)
    os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m)
    os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
const int MAX_N = 200000;
VEC<list<int>> G(MAX_N);
VEC<int> p(MAX_N, -1);
VEC<int> used(MAX_N, -1);

class Tree {
public:
  Tree *parent;
  list<Tree *> children;
  int number;
  Tree(int n) {
    number = n;
    parent = this;
  }
};

int dfs(int n) {
  // return size;
  int size = 1;
  used[n] = 1;
  for (auto v : G[n]) {
    if (!used[v]) {
      size += dfs(v);
    }
  }
  if(size>=)
  return size;
}
void make_ans(int n) {
  used[n] = 1;
  for (auto v : G[n]) {
    if (!used[v]) {
      make_ans(v);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  VEC<int> U(M), V(M);
  REP(i, 0, M) {
    cin >> U[i] >> V[i];
    --U[i];
    --V[i];
    p[U[i]] = V[i];
    p[V[i]] = U[i];
  }
  REP(i, 0, N) { cout << p[i] + 1 << " "; }

  return 0;
}
