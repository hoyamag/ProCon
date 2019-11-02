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
class Robots;
class Block;
class Blocks;
class Guide;
class Guides;
class Board;
class Cell;

class Direction {
 public:
  static char const UP = 'U';
  static char const DOWN = 'D';
  static char const LEFT = 'L';
  static char const RIGHT = 'R';
  char dir;
  Direction() { dir = 0; }
  Direction(char c) { dir = c; }
  string toString() {
    string s;
    s.push_back(dir);
    return s;
  }
  bool isUp() { return dir == UP; }
  bool isDown() { return dir == DOWN; }
  bool isLeft() { return dir == LEFT; }
  bool isRight() { return dir == RIGHT; }
};
class Position {
  static int n;

 public:
  int y, x;
  Position() {
    y = -1;
    x = -1;
  };
  Position(int ny, int nx) {
    this->y = (n + ny) % n;
    this->x = (n + nx) % n;
  }
  string toString() { return to_string(y) + " " + to_string(x); }
  void update(int ny, int nx) {
    this->y = (n + ny) % n;
    this->x = (n + nx) % n;
  }
  Position nextPosition(Direction dir) {
    if (dir.isUp()) {
      return Position(y - 1, x);
    } else if (dir.isDown()) {
      return Position(y + 1, x);
    } else if (dir.isLeft()) {
      return Position(y, x - 1);
    } else if (dir.isRight()) {
      return Position(y, x + 1);
    }
    return Position(y, x);
  }
  bool operator==(const Position &b) { return (y == b.y) && (x == b.x); }
};
class Robot {
 public:
  int id;
  Position pos;
  Direction dir;
  Robot() {
    id = -1;
    this->pos = Position();
    this->dir = Direction();
  }
  Robot(int id, int y, int x, char c) {
    this->id = id;
    this->pos = Position(y, x);
    this->dir = Direction(c);
  }
  void next_turn(Board &board, const Position &goal) {
    if (pos == goal) {
      return;
    }
    Cell &cell = board.get(pos);
    if (cell.isGuideAvailable()) {
      auto guide = *cell.guide;
      dir = guide.dir;
    }
    auto next_pos_raw = pos.nextPosition(dir);
    auto &next_cell = board.get(next_pos_raw);
    if (next_cell.isBlockAvailable()) {
      return;
    }
    cell.removeRobot(id);
    next_cell.addRobot(id);
    pos = next_pos_raw;
  }
};
class Board {
  VEC<VEC<Cell>> board;

 public:
  Board() {}
  Board(int n, Robots robots, Blocks blocks, Guides guides) {
    board = VEC<VEC<Cell>>(n, VEC<Cell>(n));
    REP(i, 0, robots.size()) {
      auto t = robots.robots[i];
      board[t.pos.y][t.pos.x].robots.insert(t.id);
    }
    REP(i, 0, blocks.size()) {
      auto t = blocks.blocks[i];
      board[t.pos.y][t.pos.x].block = &t;
    }
    REP(i, 0, guides.size()) {
      auto t = guides.guides[i];
      board[t.pos.y][t.pos.x].guide = &t;
    }
  }
  size_t size() { return board.size(); }
  Cell &get(const Position &p) { return board[p.y][p.x]; }
};
class Cell {
 public:
  set<int> robots;
  Block *block;
  Guide *guide;
  bool robotArrived;
  Cell() {
    block = NULL;
    guide = NULL;
    robotArrived = false;
  }
  bool isRobotAvailable() { return robots.size() != 0; }
  bool isBlockAvailable() { return block != NULL; }
  bool isGuideAvailable() { return guide != NULL; }
  void removeRobot(int id) { robots.erase(id); }
  void addRobot(int id) {
    robots.insert(id);
    robotArrived = true;
  }
  // Cell(Robot *r, Block *b, Guide *g){
  //   robot=r;
  //   block=b;
  //   guide=g;
  // }
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
  size_t size() { return guides.size(); }
};
class Robots {
 public:
  VEC<Robot> robots;
  Robots() {}
  Robots(int n) { robots = VEC<Robot>(n); }
  size_t size() { return robots.size(); }
};
class Blocks {
 public:
  VEC<Block> blocks;
  Blocks() {}
  Blocks(int n) { blocks = VEC<Block>(n); }
  size_t size() { return blocks.size(); }
};
class Simulator {
 public:
  Robots robots;
  Blocks blocks;
  Guides guides;
  Board board;
  Position goal;
  Simulator() {}
  Simulator(Robots r, Blocks b, Guides g, Board board, Position goal) {
    robots = r;
    blocks = b;
    guides = g;
    this->board = board;
    this->goal = goal;
  }
  LL simulate() {
    int n = board.size();
    REP(i, 0, n * n) { simulate_next(); }
  }
  void simulate_next() {
    REP(i, 0, robots.size()) { robots.robots[i].next_turn(board, goal); }
  }
  LL calc_score() {
    int A = board.get(goal).robots.size();
    int B = guides.size();
    int C = 0;
    REP(y, 0, board.size()) {
      REP(x, 0, board.size()) {
        if (board.get(Position(y, x)).robotArrived) C++;
      }
    }
    return calculate_point(A, B, C);
  }
  LL calculate_point(int A, int B, int C) { return 1000 * A - 10 * B + C; }
};
int N, RobotNum, BlockNum;
Position Goal;
Guides G;
Robots R;
Blocks B;


int main() {
  cin >> N >> RobotNum >> BlockNum;
  int gy, gx;
  cin >> gy >> gx;
  Goal = Position(gy, gx);
  R = Robots(RobotNum);
  REP(i, 0, RobotNum) {
    int y, x;
    char c;
    cin >> y >> x >> c;
    R.robots[i] = Robot(i, y, x, c);
  }
  B = Blocks(BlockNum);
  REP(i, 0, BlockNum) {
    int y, x;
    cin >> y >> x;
    B.blocks[i] = Block(y, x);
  }
  G = Guides(0);
  Board board = Board(N, R, B, G);
  Simulator sim = Simulator(R, B, G, board, Goal);
  sim.simulate();
  cerr<<sim.calc_score()<<endl;

  // Output
  cout << G.toString() << endl;

  return 0;
}
