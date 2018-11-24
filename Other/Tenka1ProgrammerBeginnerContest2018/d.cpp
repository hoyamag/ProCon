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

int n;

int main() {
  cin >> n;
  int k = 1;
  LL a;
  VEC<list<pair<int, int>>> G(1e5);
  for (a = 0; a * (a - 1) / 2 < n; ++a) {
  }
  if (a * (a - 1) / 2 == n) {
    REP(i, 0, a) {
      REP(j, i + 1, a) {
        G[i].push_back({j, k});
        G[j].push_back({i, k});
        // DUMP(i,k);
        ++k;
      }
    }
    cout<<"Yes"<<endl;
    cout << a << endl;
    REP(i, 0, a) {
      cout << G[i].size() << " ";
      int q = G[i].size();
      REP(j, 0, q) {
        auto p = G[i].front();
        cout << p.second << " ";
        G[i].pop_front();
      }
      cout << endl;
    }
  } else
    cout << "No" << endl;
  return 0;
}
