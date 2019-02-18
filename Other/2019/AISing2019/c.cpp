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

int main() {
  int h, w;
  cin >> h >> w;
  VEC<string> s(h);
  REP(i, 0, h) cin >> s[i];
  queue<int> nh;
  queue<int> nw;
  LL answer = 0;
  auto visit = MATINIT(bool, h, w, 0);
  REP(i, 0, h) {
    REP(j, 0, w) {
      int blcnt=0;
      if (s[i][j] == '.') continue;
      nh.push(i);
      nw.push(j);
      LL ans = 0;
      while (!nh.empty() && !nw.empty()) {
        int ch = nh.front();
        int cw = nw.front();
        nh.pop();
        nw.pop();
        char cc = s[ch][cw];
        if (visit[ch][cw]) continue;
        visit[ch][cw] = 1;
        if (cc == '.') {
          ++ans;
          // DUMP(i,j,"to",ch,cw);
        }else{
          ++blcnt;
        }
        if (ch + 1 < h && cc != s[ch + 1][cw]) {
          nh.push(ch + 1);
          nw.push(cw);
        }
        if (ch - 1 >= 0 && cc != s[ch - 1][cw]) {
          nh.push(ch - 1);
          nw.push(cw);
        }
        if (cw + 1 < w && cc != s[ch][cw + 1]) {
          nh.push(ch);
          nw.push(cw + 1);
        }
        if (cw - 1 >= 0 && cc != s[ch][cw - 1]) {
          nh.push(ch);
          nw.push(cw - 1);
        }
      }
      answer += blcnt*ans;
    }
  }
  cout << answer;

  return 0;
}
