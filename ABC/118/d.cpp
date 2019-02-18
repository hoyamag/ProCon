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
int n, m;
VEC<int> num2mat = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
VEC<int> mat2num(10, -1);
const int matlim = 8;
VEC<int> a;
LL dfs(int num, int keta) {
  LL ma = -1;
  if (keta == 0) {
    return num == 0 ? 0 : -1;
  }
  int mi = -1;
  REP(i, 0, matlim) {
    if (mat2num[i] > 0) {
      LL t = dfs(num - mat2num[i], keta - 1);
      if (ma < t) {
        mi = mat2num[i];
        ma = t;
      }
    }
  }
  return mi * pow(10, keta - 1) + ma;
}

int main() {
  cin >> n >> m;
  a = VEC<int>(m);
  REP(i, 0, m) {
    cin >> a[i];
    int mat = num2mat[a[i]];
    mat2num[mat] = max(mat2num[mat], a[i]);
  }
  DUMP(mat2num);
  LL ma = 0;
  REP(i,1,n/2+1){
    ma=max(ma,dfs(n,i));
  }
  cout<<ma<<endl;

  return 0;
}
