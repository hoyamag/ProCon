# KUPC 2018 参加記(ABCD解き)
コンテストページ：https://beta.atcoder.jp/contests/kupc2018
提出：https://beta.atcoder.jp/contests/kupc2018/submissions?f.User=skjmp

結果は229:49で800点(7WA) でした。


## A
素直に要素について面積を求めて最大値を記憶すれば良さそうです。

提出コードは以下になりました。
```c++
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
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  int n;
  cin >> n;
  VEC<int> s(n), a(n);
  REP(i, 0, n) cin >> s[i];
  REP(i, 0, n) cin >> a[i];
  LL ma = 0;
  REP(i, 0, n) { ma = max(ma, (LL)s[i] * a[i]); }
  cout << ma << endl;

  return 0;
}

```
最大値を格納する変数maをlong longで宣言していますが、制約を見るとたかだか100*100なので、intで十分でした。

## B
* 自機の前3マスだけが移動可能な範囲で、同じマスを繰り返し通ることはない
* 盤面が最大でも10*10

なので、全探索で通りそうです。最初の自機の位置からはじめて、前3マスを再帰的に探索することで解くことにしました。
ただ、経路復元をする必要があるところが厄介そうです。


DFSで探索を行い、1つ答えが求まった時点で探索を打ち切れば探索木の帰りがけ順が答えになりそうです。コードは下記になりました。

```c++
MAT<char> c;//弾幕ゲーム画面
int H, W;
list<char> ans; // 答えとして出力する経路を格納

bool dfs(int nh, int nw) {
  //自機の新しい位置として(nh, nw)を取り、
  //ゴール到達なら1、探索継続不可なら0を返します。
  //その判断がつかない場合、(nh, nw)の前3マスの探索を行います。

  //DUMP(nh, nw);
  if (nh == -1) {
    return 1;
  } else if (nw < 0 || W <= nw) {
    return 0;
  } else if (c[nh][nw] == 'x') {
    return 0;
  } else if (nh == 0 && c[nh][nw] != 'x') {
    return 1;
  } else {
    REP(i, 0, 3) {
      if (dfs(nh - 1, nw - 1 + i)) {
        // 答えようの経路を保存していく
        char t;
        if (i == 0)
          t = 'L';
        else if (i == 1)
          t = 'S';
        else
          t = 'R';
        ans.push_front(t);
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  ans = list<char>();
  cin >> H >> W;
  c = MATINIT(char, H, W, 0);
  REP(h, 0, H) REP(w, 0, W) cin >> c[h][w];
  //DUMP(c);
  bool possible;
  REP(w, 0, W) {// 's'の位置から探索を始める
    if (c[H - 1][w] == 's')
      possible = dfs(H - 1, w);
  }
  if (possible) {
    for (auto v : ans) {
      cout << v;
    }
  } else
    cout << "impossible";
  cout << endl;
  return 0;
}
```

## C

