#include <bits/stdc++.h>
long long syakutori(const std::vector<long long> &A,
                    std::function<bool(int)> cond) {
  // 尺取り法の実装例。 https://atcoder.jp/contests/abc130/tasks/abc130_d
  // Aの連続する部分列で、和がcondを満たすような区間[s, t)の数を数える。
  // なお仮定として「Ai>=0であり、区間の和は区間の始点を決めた時単調増加」を置いている。
  // O(N)
  long long ans = 0;
  long long sum = 0;
  long long N = A.size();
  int t = 0;
  
  // 区間開始点でループ
  for (int s = 0; s < N; ++s) {
    while (!cond(sum) && t < N) {
      // condを満たすまでtを進める
      sum += A[t];
      t++;
    }
    if (!cond(sum))
      break;  // tをいくら進めてもcondを満たせなかったので、探索終了
    
    // この区間による解でansを更新。この例題では, [s, t)が条件を満たす時[s, t')  (t'>t)も条件を満たすので、そのようにカウントする。
    ans += N - t + 1;
    // 始点を1つ進めるので、和も更新
    sum -= A[s];
  }
  return ans;
}

int main() {
  long long N, K;
  std::cin >> N >> K;
  std::vector<long long> A(N, 0);
  for (int i = 0; i < N; i++) std::cin >> A[i];
  auto cond = [&](int sum) -> bool { return sum >= K; };
  long long ans = syakutori(A, cond);
  std::cout << ans << std::endl;

  return 0;
}
