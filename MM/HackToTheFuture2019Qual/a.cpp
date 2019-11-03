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
ostream &operator<<(ostream &os, set<T> const &s) {
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

class Direction {
 public:
  static char const UP = 'U';
  static char const DOWN = 'D';
  static char const LEFT = 'L';
  static char const RIGHT = 'R';
  char dir;
  Direction() { dir = 0; }
  Direction(char c) {
    dir = c;
    cerr << "Direction constructor: dir=" << dir << ", c=" << c << endl;
  }

  string toString() {
    string s;
    s.push_back(dir);
    return s;
  }
  bool isUp() const { return dir == UP; }
  bool isDown() const { return dir == DOWN; }
  bool isLeft() const { return dir == LEFT; }
  bool isRight() const { return dir == RIGHT; }
  string toString() const {
    cerr << "Direction, toString, dir " << dir << endl;
    cerr << "string(1, dir)" << string(1, dir) << endl;
    return string(1, dir);
  }
  char toChar() const {
    cerr << "Direction, toChar, dir " << dir << endl;
    return (dir);
  }
};
Direction DirectionUp = Direction('U');
Direction DirectionDown = Direction('D');
Direction DirectionLeft = Direction('L');
Direction DirectionRight = Direction('R');
class Position {
 public:
  static int N;
  int y, x;
  Position() {
    y = -1;
    x = -1;
  };
  Position(int ny, int nx) {
    this->y = (N + ny) % N;
    this->x = (N + nx) % N;
  }
  Position up() const { return Position(y - 1, x); }
  Position down() const { return Position(y + 1, x); }
  Position left() const { return Position(y, x - 1); }
  Position right() const { return Position(y, x + 1); }
  string toString() { return to_string(y) + " " + to_string(x); }
  void update(int ny, int nx) {
    this->y = (N + ny) % N;
    this->x = (N + nx) % N;
  }
  Position const nextPosition(Direction const dir) {
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
  string toString() const {
    return "(" + to_string(y) + "," + to_string(x) + ")";
  }
  bool operator==(Position const &b) const { return (y == b.y) && (x == b.x); }
};
int Position::N;

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
    this->dir = d;
  }
  Guide(int y, int x, char c) {
    auto g = Guide(Position(y, x), Direction(c));
    this->pos = g.pos;
    this->dir = g.dir;
  }
  string toString() { return pos.toString() + " " + dir.toString(); }
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
  string toString() const {
    stringstream ss;
    ss << "id:" << id << " pos" << pos.toString() << " dir:" << dir.toString();
    return ss.str();
  }
  Position getPosition() const { return pos; }
};
class Robots {
 public:
  VEC<Robot> robots;
  Robots() {}
  Robots(int n) { robots = VEC<Robot>(n); }
  size_t size() { return robots.size(); }
  string toString() const {
    stringstream ss;
    for (auto &v : robots) ss << v.toString() << endl;
    return ss.str();
  }
};
class Blocks {
 public:
  VEC<Block> blocks;
  Blocks() {}
  Blocks(int n) { blocks = VEC<Block>(n); }
  size_t size() { return blocks.size(); }
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
  void addGuide(Guide g) {
    cerr << hex << &(g.dir.dir) << endl;
    cerr << "Add Guide " << g.toString() << endl;
    guide = new Guide(g.pos, g.dir);
    cerr << "Add Guide " << guide->toString() << endl;
  }
  void removeGuide() { guide = NULL; }
  char toChar() const {
    if (robots.size() != 0) return 'R';
    if (block != NULL) return 'B';
    if (guide != NULL) {
      cerr << "guide->dir.toChar():" << (guide->dir.toChar())
           << ", guide->dir.dir:" << guide->dir.dir << endl;
      return guide->dir.toChar();
    }

    return '.';
  }
  // Cell(Robot *r, Block *b, Guide *g){
  //   robot=r;
  //   block=b;
  //   guide=g;
  // }
};
class Board {
  VEC<VEC<Cell>> board;

 public:
  Board() {}
  Board(int n, Robots robots, Blocks blocks, Guides guides) {
    board = VEC<VEC<Cell>>(n, VEC<Cell>(n));
    REP(i, 0, robots.size()) {
      auto t = robots.robots[i];
      board[t.pos.y][t.pos.x].addRobot(i);
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
  void show() const {
    REP(y, 0, board.size()) {
      REP(x, 0, board.size()) { cerr << board[y][x].toChar(); }
      cerr << endl;
    }
    cerr << endl;
  }
};

void robot_next_turn(Robot &robot, Board &board, Position const &goal) {
  if (robot.pos == goal) {
    return;
  }
  Cell &cell = board.get(robot.pos);
  if (cell.isGuideAvailable()) {
    auto guide = *cell.guide;
    robot.dir = guide.dir;
  }
  // auto next_pos_raw = nextRobot.getPosition()(nextRobot.dir);
  auto next_pos_raw = robot.getPosition().nextPosition(robot.dir);
  auto &next_cell = board.get(next_pos_raw);
  if (next_cell.isBlockAvailable()) {
    return;
  }
  cell.removeRobot(robot.id);
  next_cell.addRobot(robot.id);
  //   cerr << "prev"<<cell.robots << endl;
  //   cerr << "next"<<next_cell.robots << endl;
  robot.pos = next_pos_raw;
}

class Simulator {
 public:
  Robots robots;
  Blocks blocks;
  Guides guides;
  Board *board_p;
  Position goal;
  Simulator() {}
  Simulator(Robots &r, Blocks &b, Guides &g, Board &board, Position &goal) {
    robots = r;
    blocks = b;
    guides = g;
    this->board_p = &board;
    this->goal = goal;

    // cerr << "board" << hex << &board << endl;
    // cerr << "this->board" << hex << &(this->board_p) << endl;
  }
  LL simulate() {
    Board &board = *board_p;
    int n = board.size();
    REP(i, 0, n * n) { simulate_next(); }
    return calc_score();
  }
  void simulate_next() {
    Board &board = *board_p;
    REP(i, 0, robots.size()) { robot_next_turn(robots.robots[i], board, goal); }
    board.show();
    // cerr << robots.toString() << endl;
  }
  LL calc_score() {
    Board &board = *board_p;
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

class GuideLocator {
 public:
  VEC<VEC<bool>> used;
  GuideLocator(int N) { used = VEC<VEC<bool>>(N, VEC<bool>(N, false)); }
  void locate_guide(Board &board, Position pos, Direction dir) {
    // cerr << hex << &board << endl;
    // cerr << "a" << pos.toString() << endl;
    if (used[pos.y][pos.x]) return;
    // cerr << "b" << pos.toString() << endl;
    used[pos.y][pos.x] = true;
    auto &cell = board.get(pos);
    if (cell.isBlockAvailable()) return;
    // cerr << "c" << pos.toString() << endl;
    cell.addGuide(Guide(pos, dir));
    locate_guide(board, pos.up(), DirectionDown);
    locate_guide(board, pos.down(), DirectionUp);
    locate_guide(board, pos.left(), DirectionRight);
    locate_guide(board, pos.right(), DirectionLeft);
  }
};
int main() {
  int N, RobotNum, BlockNum;
  Position Goal;
  Guides G;
  Robots R;
  Blocks B;
  cin >> N >> RobotNum >> BlockNum;
  Position::N = N;
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
  // cerr << "board in main" << hex << &board << endl;
  Simulator sim = Simulator(R, B, G, board, Goal);
  GuideLocator guide_locator = GuideLocator(N);
  guide_locator.locate_guide(board, Goal, DirectionUp);
  board.get(Goal).removeGuide();

  sim.simulate();
  cerr << "score " << sim.calc_score() << endl;

  // Output
  cout << G.toString() << endl;

  return 0;
}
