
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
template <typename T>
ostream &operator<<(ostream &os, list<T> &vec) {
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
int N;
VEC<int> A, B;
VEC<int> C(101, 0);
list<int> ans;
int dfs(list<int> &a) {
  // DUMP(a);
  // int n = a.size();
  if (a.size() == 0) {
    return 1;
  }
  int i = 0;
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (*it == i + 1) {
      it = a.erase(it);
      C[i+1]--;
      if(C[i+1<0])return 0;
      // DUMP("t", t);
      if (dfs(a)) {
        ans.push_back(i + 1);
        return 1;
      }
      it = a.insert(it, i + 1);
      C[i+1]++;
    }
    ++i;
  }
  return 0;
}

int main() {
  // list<int> a = {1, 2, 3};
  // auto it = a.begin();
  // it++;
  // auto it2 = a.erase(it);
  // DUMP(a);
  // DUMP(*it);
  // DUMP(*it2);
  // auto it3 = a.insert(it2, 4);
  // DUMP(a);
  // DUMP(*it3);

  cin >> N;
  B = VEC<int>(N);

  REP(i, 0, N) {
    cin >> B[i];
    C[B[i]]++;
  }
  list<int> b(ALL(B));
  if (B[0] != 1) {
    cout << -1 << endl;
    return 0;
  }
  if (dfs(b)) {
    for (auto v : ans) {
      printf("%d\n",v);
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
