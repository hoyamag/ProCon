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
掛け算をすることに気づいた当時の私は、最大値を格納する変数maをlong longで宣言していますが、制約を見るとたかだか100*100なのでintで十分でした。

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
        // 答え用に経路を保存していく
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
入力がない問題ははじめてだったのでびっくりしました。
C++で答えとなる文字列を定義して提出していましたが、提出言語をTextにしたほうが楽だったようです。

よくわからなかったのでなんとなく次のような系列を出していました(1つ目はWAです)
```
......#..
.....#...
....#....
...#.....
..#......
.#.......
#.....###
......#..
......#..
```

```
......#..
.....#...
....#....
...#.....
..#......
.#####...
#.....###
......#..
......#..
```

これで33点を出し、ここではじめて順位表を見ました。この問題の満点が何点なのか知りたかったのです。200点でした(そういえば配点にも200点て書いてますね）。

さて、気を取り直して、満点解法を目指します。点数計算が$floor(200/max(1, N-10))$ ただしNは置いた#の数  なので、11個まで置けます。

1個#を置くときに、それで遮れるラインが多いと嬉しそうです。
また「このラインを塞ぐためにはこのマスのうちのどこかに置かなければならない」という風に
置くマスの候補を限定も出来そうです。

とりあえず絶対置かなそうな場所を考えました
```
XX.....XX
XX.....XX
.........
.........
.........
.........
.........
XX.....XX
XX.....XX
```

そして、それぞれの端2列と、2行を塞ぐために、a~hので示した位置に1個ずつ、
#を置く必要があることに気づきました。
```
XXcccccXX
XXdddddXX
ab.....ef
ab.....ef
ab.....ef
ab.....ef
ab.....ef
XXgggggXX
XXhhhhhXX
```

ここまでで8個の使いみちが決まって、残り3個で真ん中らへんのラインを塞ぐことになります。


```
XX..#..XX
XX..#..XX
.........
.........
##.....##
.........
.........
XX..#..XX
XX..#..XX
```
↑適当に置きました。置いたあとこんな置き方では
足りないことに気づいたので、a~hにおく#の位置を工夫して、より多くのラインが塞げるようにします。

```
XX.#...XX
XX...#.XX
.........
#......#.
.........
.#......#
.........
XX.#...XX
XX...#.XX
```
↑左右（上下）の#を対になるように置くことで距離を6に抑える天才的な発想をしました。
しかしこの状態で真ん中付近を通るラインを3個の#で塞げないか試しましたがダメでした。

```
XX#....XX
XX....#XX
#......#.
.........
.........
.........
.#......#
XX#....XX
XX....#XX
```

↑別パターンを試しました。この試行はうまくいってACしました.
答えは以下です。

```
..#......
......#..
#......#.
...#.....
....#....
.....#...
.#......#
..#......
......#..
```

感想ですが、配点と計算方法から「満点解法の場合における#の数」を出していれば、WAが減らせたと思います。
また、天才的な発想をした直後に試した系列がダメだとわかってから、
別パターンを試してACするまでの時間が長かったので、
「ある仮定のもとに考察を進めている(これがダメだとわかったら別パターンの
HOGEで考察をすすめるべき)」という状態に意識的であれたらいいなと思いました。

# D
何もわからなかったのでとりあえず実験をしました。
#TODO 画像

3, 4, 5, 7でmodを取った時の値とその偶奇を書いています。
そして、modを取った値の偶奇が元の数値の偶奇と違っていれば丸を書いています(シャーペンなので見えづらいですね)。

* mod 3, mod 5の実験で、「modを取った値の偶奇と元の値の偶奇の不一致は周期的に出てくる」
っぽいことがわかりましたが、それで解けるまで落ちてきませんでした。
* mod 4の実験で、「偶数でmodをとっても、元の値と偶奇は変わらない」っぽいことがわかりました(今思えば根拠弱過ぎな気がします)。
* mod 7の実験で、「14未満までの範囲だけを考えれば、7未満は元の値と偶奇が変わらず、7以上は偶奇が変わることがわかりました」。

mod 7の実験結果から、1回のクエリで解の候補となる区間を半分に
出来そうなことがわかりました。ただ、
* 解の候補区間 $1 \le X \le 10^9$ に対し発行できるクエリが$1 \le q \le 10^9$なので、
  答えが1e9の場合特別な処理が必要そう(答えの数値の本来の偶奇が取れないので)($1 \le q \le 10^9+1$だと嬉しかった)
  *  答えが1e9の場合は、最初のクエリ(1e9)を与えた時に'even'が帰ってきて、
    それ以降のクエリでは毎回'odd'が返ってくることが実験でわかったので
    それで判定することにしました

ということで、解の候補区間を二分する奇数でクエリを発行していくニブタンを書きます。
クエリの数30回は、ぎりぎりなので、余計なクエリを発行しないように気をつけましょう
(そもそも事前にチェックしましょう)(6WAくらいしました)

コードです.
```c++
int main() {
  LL left = 1, right = 1e9;
  LL maxRange = right;
  cout << "? " << right << endl;
  string original;
  cin >> original;
  int cnt = 1;
  LL mid;
  string midEvenOdd;
  bool maxFlag = original == "even";// 答えが1e9だったときを判定する用
  while (abs(right - left) > 2) {
    ++cnt;
    mid = (left + right) / 2;
    mid += mid % 2 == 0 ? 1 : 0;
    DUMP(cnt, left, mid, right);
    cout << "? " << mid << endl;
    cin >> midEvenOdd;
    if (midEvenOdd == original) {
      right = mid;
    } else {
      left = mid;
    }
    maxFlag = (maxFlag && midEvenOdd == "odd");
  }
  mid = (left + right) / 2;
  DUMP(cnt, left, mid, right);
  if (maxFlag) {
    cout << "! " << maxRange << endl;
  } else {
    // midに奇数を取るよう補正した関係上、
    // この時点でまだ解の候補に{left, left+1}の2つがあります。
    // {left, left+1}の偶奇見て、最初のクエリでとった偶奇と等しい方を答えにします。
 
    REP(i, left, right) {
      string s = (i % 2 == 0 ? "even" : "odd");
      if (s == original)
        cout << "! " << i << endl;
    }
  }
  return 0;
}
```

感想ですが、
* にぶたんするのはいいけどクエリの最大回数で探索が終わるかは書く前に考えたほうが良い