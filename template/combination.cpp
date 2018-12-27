std::vector<std::vector<long long>> combTableByPascalsTriangle(int n) {
  /*パスカルの三角形を利用した組合せの前計算。O(N^2)。
   * arg...
   *  int n: 組合せ計算したい要素の個数。nCrで指定しうる最大のn
   * return...
   *  vector<vector<long long>> c : 組合せ計算nCrの結果がc[n][r]に入っている。
  */
  auto c = std::vector<std::vector<long long>>(
      n + 1, std::vector<long long>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 or j == i) {
        c[i][j] = 1LL;
      } else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
      }
    }
  }
  return c;
}
