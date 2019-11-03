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
class Takahashi;
class Quest;
const int T = 1000;
const int N = 10;
const int M = 30000;
const int BAITO_MONEY = 1000;
class Quest {
 public:
  int A, B;
  LL C;
  vector<int> S;
  Quest() {
    cin >> A >> B >> C;
    S = VEC<int>(N);
    REP(i, 0, N) cin >> S[i];
  }
  Quest(bool a) {
    A = -1;
    B = -1;
    C = -1;
    VEC<int> S(N, -1);
  }
  string toString() {
    stringstream q;
    q << A << " " << B << " " << C << " ";
    REP(i, 0, N) q << S[i] << " ";
    return q.str();
  }
};
class Takahashi {
 public:
  int _turn;
  LL _money;
  VEC<int> _skill;
  int _skillsum = 0;
  VEC<string> _command;
  Takahashi() {
    _turn = 1;
    _money = 0;
    _skill = VEC<int>(N, 0);
    _command = VEC<string>(T + 1, " ");
  }
  void doSkillup(int nth, int duration, LL cost) {
    // return pass turn;
    REP(t, _turn, min(T + 1, _turn + duration)) {
      _command[t] = "1 " + to_string(nth + 1);
    }
    ++_skill[nth];
    ++_skillsum;
    _turn += duration;
    _money -= cost;
  }
  pair<int, LL> evalSkillUp(int nth) {
    // return <turn, money>
    if (_skill[nth] == 10) {
      return {1, 0};
    } else {
      int next_level = _skill[nth] + 1;
      int duration = next_level;
      LL cost = 10000 * (LL)pow(2, next_level);
      cost *= duration;
      return {duration, cost};
    }
  }
  void doBaito() {
    _money += 1000;
    _command[_turn] = "3";
    ++_turn;
  }
  void doQuest(LL prize, Quest *q, int nth) {
    _command[_turn] = "2 " + to_string(nth + 1);
    _money += prize;
    ++_turn;
    q->A = -1;
    q->B = -1;
    q->C = -1;
  }

  LL evalQuest(const Quest &q) {
    if (q.A <= _turn && _turn <= q.B) {
      double AddMoney = q.C;
      AddMoney *= (1 + 9 * (double)(_turn - q.A) / (q.B - q.A));
      int SkillLack = 0;
      for (int j = 0; j < N; j++) SkillLack += max(0, q.S[j] - _skill[j]);

      if (SkillLack == 0)
        AddMoney *= 10;
      else {
        AddMoney *= pow(0.5, SkillLack);
        AddMoney += 1e-9;
      }
      
      return (LL)AddMoney;
    } else
      return 0;
  }

  pair<int, LL> evalMaxQuest(const VEC<Quest> &q) {
    LL eval_quest_prize = 1000;
    int eval_quest_num = -1;
    REP(i, 0, M) {
      int cand = evalQuest(q[i]);
      if (cand > eval_quest_prize) {
        eval_quest_prize = cand;
        eval_quest_num = i;
      }
    }
    return {eval_quest_num, eval_quest_prize};
  }
  string toString() {
    stringstream q;
    q << _turn << " " << _money << " ";
    REP(i, 0, N) q << _skill[i] << " ";
    return q.str();
  }
  void outputCommand() {
    REP(i, 1, T + 1) {
      if (_command[i][0] != ' ') cout << _command[i] << endl;
    }
  }
};
class Part1Simulator {
 public:
  Takahashi _takahashi;
  VEC<Quest> _quest;
  VEC<int> _skill_order;
  Part1Simulator() {}
  Part1Simulator(VEC<Quest> arg_quest, VEC<int> &so) {
    _takahashi = Takahashi();
    _quest = arg_quest;
    _skill_order = so;

    VEC<pair<int, LL>> eval(N, {-1, BAITO_MONEY});
    int next_skill = _skill_order[_takahashi._skillsum];
    while (_takahashi._turn <= T) {
      auto eval_skill = _takahashi.evalSkillUp(next_skill);
      LL eval_quest_prize = 1000;
      LL eval_quest_num = -1;

      REP(i, 0, M) {
        int cand = _takahashi.evalQuest(_quest[i]);
        if (cand > eval_quest_prize) {
          eval_quest_prize = cand;
          eval_quest_num = i;
        }
      }
      // DUMP("eval_skil", eval_skill);
      if (_takahashi._skill[next_skill] < 10 && eval_skill.second != 0 &&
          eval_skill.second < _takahashi._money &&
          eval_skill.first < T - _takahashi._turn) {
        _takahashi.doSkillup(next_skill, eval_skill.first, eval_skill.second);
        next_skill = _skill_order[_takahashi._skillsum];
        if (_takahashi._skillsum == 100) {
          return;
        }
        // DUMP("Skill");
      } else if (eval_quest_prize > 1000) {
        // DUMP("Quest");
        // DUMP("  ", quest[eval_quest_num].toString());
        _takahashi.doQuest(eval_quest_prize, &_quest[eval_quest_num],
                           eval_quest_num);
        // DUMP("  ", quest[eval_quest_num].toString());

      } else {
        _takahashi.doBaito();
        // DUMP("Baito");
      }
      // DUMP(taka.toString());
    }
    //int next_skill = _skill_order[_takahashi._skillsum];
    //auto eval_skill = _takahashi.evalSkillUp(next_skill);
    //int skill_fee = eval_skill.second;
    //auto tmp_quest = _quest;
    //LL gain = 0;
    //list<pair<int, Quest>> q;
    //while (_takahashi._money + gain < skill_fee) {
      //auto res = _takahashi.evalMaxQuest(tmp_quest);
      //q.push_back({res.first, _quest[res.first]});
      //gain+= res.second;
    //}
  }
};
class Part2Simulator {
 public:
  Takahashi _takahashi;
  VEC<Quest> _quest;
  Part2Simulator(const Part1Simulator &p1) {
    _takahashi = p1._takahashi;
    _quest = p1._quest;

    VEC<pair<int, LL>> plan(T + 1, {-1, 0});  // index, prize

    int mighty_begin = _takahashi._turn;
    for (int t = T; t >= mighty_begin; --t) {
      _takahashi._turn = t;
      LL max_value = -1;
      int max_index = -1;
      REP(q, 0, M) {
        LL cand = _takahashi.evalQuest(_quest[q]);
        if (cand > max_value) {
          max_value = cand;
          max_index = q;
        }
      }
      plan[t].first = max_index;
      plan[t].second = max_value;
      _quest[max_index].A = -1;
      _quest[max_index].B = -1;
      _quest[max_index].C = -1;
    }
    REP(t, mighty_begin, T + 1) {
      _takahashi.doQuest(plan[t].second, &_quest[plan[t].first], plan[t].first);
      // DUMP(_quest[plan[t].first].toString());
    }
  }
};

std::mt19937 MT(25);
const int TIMELIMIT = 2750;
int randInRange(int minimum, int maximum) {
  return minimum + MT() % (maximum - minimum + 1);
}

int main() {
  auto startTime = chrono::system_clock::now();
  int a;
  cin >> a >> a >> a;
  VEC<Quest> quest(M);
  VEC<int> order(100);
  REP(i, 0, N) REP(j, 0, N) { order[i * N + j] = j; }
  int64_t msec = 0;

  Part1Simulator best = Part1Simulator(quest, order);
  auto best_order = order;
  while (msec < TIMELIMIT) {
    // DUMP(order);
    int randa, randb;
    randa = randb = 0;
    while (randa == randb || order[randa] == order[randb]) {
      randa = randInRange(0, 49);
      randb = randInRange(0, 49);
    }
    swap(order[randa], order[randb]);

    auto current = Part1Simulator(quest, order);
    // DUMP(current._takahashi.toString());
    if (current._takahashi._turn < best._takahashi._turn) {
      // DUMP("update");
      best = current;
      best_order = order;
    } else
      order = best_order;
    msec = chrono::duration_cast<chrono::milliseconds>(
               chrono::system_clock::now() - startTime)
               .count();
  }
  // DUMP(best._takahashi.toString());
  auto p2 = Part2Simulator(best);
  // DUMP(best._takahashi.toString());

  p2._takahashi.outputCommand();

  return 0;
}
