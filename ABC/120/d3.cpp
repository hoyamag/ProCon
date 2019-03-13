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
class DisjointSet {
  //参考 蟻本p84
  //均し計算量O(α(N))でほぼ定数
  // ついでに各setにサイズ情報を入れた(根なら、そのsetのsize情報を持ってる)

 public:
  static const int MAX_N = 1e6;

  int par[MAX_N];         // parent
  int rank[MAX_N];        // the depth of trees
  long long size[MAX_N];  // the size of sets
  int element_num;        // the number of elements
  // n要素で初期化
  DisjointSet(int n) {
    element_num = n;
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }

  // 木の根を求める
  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) { return find(x) == find(y); }

  friend ostream &operator<<(ostream &os, const DisjointSet &d);
};
ostream &operator<<(ostream &os, const DisjointSet &d) {
  os << "i, p, r, s" << endl;
  for (int i = 0; i < d.element_num; ++i) {
    os << i << ", " << d.par[i] << ", " << d.rank[i] << ", " << d.size[i]
       << endl;
  }
  return os;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  LL N, M;
  cin >> N >> M;
  VEC<pair<int, int>> edge(M);
  REP(i, 0, M) {
    cin >> edge[i].first >> edge[i].second;
    edge[i].first--;
    edge[i].second--;
  }
  reverse(ALL(edge));
  LL U = N * (N - 1) / 2;
  DisjointSet ds(N);
  list<LL> ans;
  LL sum = 0;
  REP(i, 0, M) {
    ans.push_back(U - sum);
    int x = ds.find(edge[i].first);
    int y = ds.find(edge[i].second);
    if (x != y) {
      sum += ds.size[x] * ds.size[y];
      ds.unite(x, y);
    }
  }
  for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
    cout << *it << endl;
  }
}