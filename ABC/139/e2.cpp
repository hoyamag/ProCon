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
ostream &operator<<(ostream &os, queue<T> vec) {
  os << "{";
  while (!vec.empty()) {
    os << vec.front() << ",";
    vec.pop();
  }
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

int main() {
  int N;
  cin >> N;
  // VEC<queue<int>> TO(N);
  int TO[N][N - 1];
  REP(i, 0, N) {
    REP(j, 0, N - 1) {
      scanf("%d", &TO[i][j]);
      TO[i][j]--;
    }
  }
  queue<pair<int, int>> playQueue;
  auto addPairIfPlayable = [&](pair<int, int> p) {
    static map<pair<int, int>, int> mp;
    if (p.first > p.second) swap(p.first, p.second);
    mp[p]++;
    if (mp[p] == 2) {
      playQueue.push(p);
      mp.erase(p);
    }
  };
  REP(i, 0, N) {
    auto p = make_pair((int)i, TO[i][0]);
    addPairIfPlayable(p);
  }
  VEC<int> index(N, 0);
  // 変更点をqueueに入れるように舐め方を変えると通るらしい
  // DUMP(playQueue);
  // DUMP(playQueue);
  VEC<int> lastGameDay(N, 0);
  while (playQueue.empty() == false) {
    // DUMP(playQueue);
    auto p = playQueue.front();
    playQueue.pop();
    int i = p.first;
    int j = p.second;
    if (index[i] < N - 1 && index[j] < N - 1) {
      // if (TO[i][index[i]] == j && TO[j][index[j]] == i) {
      lastGameDay[i] = lastGameDay[j] = max(lastGameDay[i], lastGameDay[j]) + 1;
      index[i]++;
      index[j]++;
      if (index[i] < N - 1) {
        auto newPair = make_pair(i, TO[i][index[i]]);
        addPairIfPlayable(newPair);
      }
      if (index[j] < N - 1) {
        auto newPair = make_pair(j, TO[j][index[j]]);
        addPairIfPlayable(newPair);
      }
      // DUMP(days, cnt, i + 1, j + 1);
    }
    // }
  }
  REP(i, 0, N) {
    if (index[i] != N - 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  LL days = *max_element(ALL(lastGameDay));
  std::printf("%lld\n", days);

  return 0;
}
