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
class Position;
class Robot;
class Block;

class Position {
 public:
  int y, x;
  Position() {
    y = -1;
    x = -1;
  };
  Position(int y, int x) {
    this->y = y;
    this->x = x;
  }
};
class Robot {
 public:
  Position pos;
  char dir;
  Robot() {
    this->pos = Position();
    dir = 0;
  }
  Robot(int y, int x, char c) {
    this->pos = Position(y, x);
    this->dir = c;
  }
};
class Block {
 public:
  Position pos;
  Block() { this->pos = Position(); }
  Block(int y, int x) { this->pos = Position(y, x); }
};
int N, RobotNum, BlockNum;
Position Goal;
VEC<Robot> R;
VEC<Block> B;

int main() {
  cin >> N >> RobotNum >> BlockNum;
  int gy, gx;
  cin >> gy >> gx;
  Goal = Position(gy, gx);
  R = VEC<Robot>(RobotNum);
  REP(i, 0, RobotNum) {
    int y, x;
    char c;
    cin >> y >> x >> c;
    R[i] = Robot(y, x, c);
  }
  B = VEC<Block>(BlockNum);
  REP(i, 0, BlockNum) {
    int y, x;
    cin >> y >> x;
    B[i] = Block(y, x);
  }

  return 0;
}
