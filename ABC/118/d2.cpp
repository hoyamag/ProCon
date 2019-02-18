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
int n, m;
VEC<int> num2mat = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
VEC<int> mat2num(10, -1);
const int matlim = 8;

VEC<int> ans;

int dfs(int n, set<int> a) {
  int minmatti=INT32_MAX;
  int minnum=INT32_MAX;
  if (n == 0) return 0;
  if(n<0)return 1;
  if(a.size()==0)return 1;
  for (auto v : a) {
    if (minmatti > num2mat[v]) {
      minmatti = num2mat[v];
      minnum = v;
    }
  }
  int mul = n / minmatti;
  int res;
  set<int> b = a;
  b.erase(minnum);
  DUMP(n, a,minnum,minmatti);
  while (mul>0){
    res = dfs(n - mul * minmatti, b);
    if (res == 0) {
      REP(i, 0, mul) ans.push_back(minnum);
      return 0;
    }
    --mul;
  }

  return dfs(n,b);
}

int main() {
  cin >> n >> m;

  ans = VEC<int>();
  
  set<int> a;
  REP(i, 0, m) {
    int t;
    cin >> t;
    a.insert(t);
  }

  dfs(n, a);
  sort(ALL(ans),greater<int>());
  DUMP(ans);
  for (auto v : ans) {
    cout << v;
  }

  return 0;
}
