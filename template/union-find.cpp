#include <iostream>
class DisjointSet {
  //参考 蟻本p84
  //均し計算量O(α(N))でほぼ定数
  // ついでに各setにサイズ情報を入れた(根なら、そのsetのsize情報を持ってる)
  static const int MAX_N = 1e5;

  int par[MAX_N];   // parent
  int rank[MAX_N];  // the depth of trees
  int size[MAX_N];  // the size of sets
  int element_num;  // the number of elements

 public:
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
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
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
int main() {
  std::cout << "0" << std::endl;
  auto d = DisjointSet(10);
  std::cout << "1" << std::endl;
  d.unite(1, 2);
  std::cout << "2" << std::endl;
  d.unite(2, 3);
  d.unite(4, 5);
  d.unite(6, 7);
  d.unite(5, 7);
  std::cout << "Display" << std::endl;
  std::cout << d << std::endl;
  std::cout << d.same(5, 7) << std::endl;
  std::cout << d << std::endl;
}