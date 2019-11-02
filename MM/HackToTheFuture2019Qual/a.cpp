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

class Direction {
 public:
  static const char UP = 'U';
  static const char DOWN = 'D';
  static const char LEFT = 'L';
  static const char RIGHT = 'R';
  char dir;
  Direction() { dir = 0; }
  Direction(char c) { dir = c; }
  string toString() {
    string s;
    s.push_back(dir);
    return s;
  }
};
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
  string toString() { return to_string(y) + " " + to_string(x); }
};
class Robot {
 public:
  Position pos;
  Direction dir;
  Robot() {
    this->pos = Position();
    this->dir = Direction();
  }
  Robot(int y, int x, char c) {
    this->pos = Position(y, x);
    this->dir = Direction(c);
  }
};
class Block {
 public:
  Position pos;
  Block() { this->pos = Position(); }
  Block(int y, int x) { this->pos = Position(y, x); }
};
class Guide {
 public:
  Position pos;
  Direction dir;
  Guide() {}
  Guide(Position pos, Direction d) {
    this->pos = pos;
    this->dir = dir;
  }
  Guide(int y, int x, char c) {
    auto g = Guide(Position(y, x), Direction(c));
    this->pos = g.pos;
    this->dir = g.dir;
  }
  string toString() { return pos.toString() + " " + dir.toString(); }
};
class Guides {
 public:
  VEC<Guide> guides;
  Guides() { guides = VEC<Guide>(0); };
  Guides(int n) { guides = VEC<Guide>(n); }
  string toString() {
    stringstream s;
    int n = guides.size();
    s << n << endl;
    REP(i, 0, n - 1) { s << guides[i].toString() << endl; }
    if (n - 1 >= 0) s << guides[n - 1].toString();
    return s.str();
  }
};
int N, RobotNum, BlockNum;
Position Goal;
VEC<Robot> R;
VEC<Block> B;
Guides G;

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
  G = Guides(0);
  cout << G.toString() << endl;

  return 0;
}
