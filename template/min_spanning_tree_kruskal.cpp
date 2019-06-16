// Ant p101
// O(|E|log|V|)
#include <bits/stdc++.h>

////union-find///////////////////////////////
class DisjointSet {
  //参考 蟻本p84
  //均し計算量O(α(N))でほぼ定数
  // ついでに各setにサイズ情報を入れた(根なら、そのsetのsize情報を持ってる)

public:
  static const int MAX_N = 1e6;

  int par[MAX_N];        // parent
  int rank[MAX_N];       // the depth of trees
  long long size[MAX_N]; // the size of sets
  int element_num;       // the number of elements

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
    if (par[x] == x)
      return x;
    return par[x] = find(par[x]);
  }

  // xとyの属する集合を併合
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rank[x] < rank[y]) {
      par[x] = y;
      size[y] += size[x];
    } else {
      par[y] = x;
      size[x] += size[y];
      if (rank[x] == rank[y])
        rank[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(int x, int y) { return find(x) == find(y); }

  friend std::ostream &operator<<(std::ostream &os, const DisjointSet &d);
};
std::ostream &operator<<(std::ostream &os, const DisjointSet &d) {
  os << "i, p, r, s" << std::endl;
  for (int i = 0; i < d.element_num; ++i) {
    os << i << ", " << d.par[i] << ", " << d.rank[i] << ", " << d.size[i]
       << std::endl;
  }
  return os;
}
///////////////////////////////////////////////
struct edge {
  int u, v, cost;
};

bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

const int MAX_E = 1e6;
edge es[MAX_E];
int V, E; // numof vertices, edges.

// input
//   es : a graph as edge list(array)
// output
//   return  sum of weight of minimum spanning tree
int kruskal() {
  std::sort(es, es + E, comp); // sort
  auto uf = DisjointSet(V);    // initialize Unionf Find Tree
  int res = 0;
  for (int i = 0; i < E; i++) {
    edge e = es[i];
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}
