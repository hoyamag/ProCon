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
const int N = 500;
const int M = 29;
const int L = 300;
VEC<string> board(M, string(M, '.'));
VEC<string> inputCommand(N);
enum CellType {
  NORMAL = '.',
  DOUBLE = 'D',
  TRIPLE = 'T',
  LEFT = 'L',
  RIGHT = 'R',
  WALL = '#'
};
enum CommandType { CTStraight = 'S', CTLeft = 'L', CTRight = 'R' };
enum Direction { LEFT, UP, RIGHT, DOWN };
map<Direction, pair<int, int>> DirectionMovement{
    {UP, {0, -1}}, {DOWN, {0, 1}}, {LEFT, {-1, 0}}, {RIGHT, {1, 0}}};

Direction operator++(Direction a) {
  switch (a) {
    case Direction::LEFT:
      return Direction::UP;
    case Direction::UP:
      return Direction::RIGHT;
    case Direction::RIGHT:
      return Direction::DOWN;
    case Direction::DOWN:
      return Direction::LEFT;
  }
}
Direction operator--(Direction a) {
  switch (a) {
    case Direction::LEFT:
      return Direction::DOWN;
    case Direction::UP:
      return Direction::LEFT;
    case Direction::RIGHT:
      return Direction::UP;
    case Direction::DOWN:
      return Direction::RIGHT;
  }
}

Direction Turn(Direction current, bool Left) {
  int diff = Left ? 1 : -1;
  if (Left)
    return ++current;
  else
    return --current;
}
tuple<int, int, Direction> next_pos(char command, int h, int w, Direction dir) {
  char cell = board[h][w];
  Direction newdir = dir;

  int multipler = 1;
  if (cell == CellType::DOUBLE) {
    multipler = 2;
  } else if (cell == CellType::TRIPLE) {
    multipler = 3;
  } else if (cell == CellType::LEFT) {
    if (command == CommandType::CTRight) command = CommandType::CTLeft;

  } else if (cell == CellType::RIGHT) {
    if (command == CommandType::CTLeft) command = CommandType::CTRight;
  }
  if (command == CommandType::CTLeft || command == CommandType::CTRight) {
    REP(i, 0, multipler) {
      newdir = Turn(newdir, command == CommandType::CTLeft);
    }
    return make_tuple(h, w, newdir);
  }
  int nh = h, nw = w;
  REP(i, 0, multipler) {
    int dh, dw;
    tie(dh, dw) = DirectionMovement[dir];
    nh += dh;
    nw += dw;
    char cnext = board[nh][nw];
    if (cnext == CellType::WALL) {
      return make_tuple(nh - dh, nw - dw, dir);
    }
  }
  return make_tuple(nh, nw, dir);
}

LL simulate() {
  LL score = 0;
  VEC<VEC<int>> count = MATINIT(int, M, M, 0);
  REP(i, 0, N) {
    int h = 14, w = 14;
    Direction dir = UP;
    REP(j, 0, L) {
      char com = inputCommand[i][j];
      tie(h, w, dir) = next_pos(com, h, w, dir);
    }
    ++count[h][w];
  }
  REP(i, 0, M) {
    REP(j, 0, M) {
      int add = 0;
      switch (count[i][j]) {
        case 1:
          add = 10;
          break;
        case 2:
          add = 3;
          break;
        case 3:
          add = 1;
          break;
      }
      score += add;
    }
  }
  return score;
}

int main() {
  int a;
  cin >> a >> a >> a;
  REP(i, 0, N) cin >> inputCommand[i];
  REP(i, 0, M)
  REP(j, 0, M)
  if (i == 0 || i == M - 1 || j == 0 || j == M - 1) board[i][j] = '#';
  LL score = simulate();
  cerr << score << endl;
  REP(i, 0, M) cout << board[i] << endl;

  return 0;
}
