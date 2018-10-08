#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
map<int, int> primeCount(int n) {
  map<int, int> pc;
  LL ma = ceil(sqrt(n));
  REPC(i, 2, ma) {
    while (n % i == 0) {
      n /= i;
      ++pc[i];
    }
  }
  if (n > 1) {
    ++pc[n];
  }
  return pc;
}

int main() {
  LL N, M;
  cin >> N >> M;
  auto pc = primeCount(M);
  VEC<LL> s;
  s.push_back(1);
  for (auto v : pc) {
    int siz = s.size();
    REP(k, 0, siz) {
      LL sum = s[k];
      REP(i, 0, v.second) {
        sum *= v.first;
        s.push_back(sum);
      }
    }
  }
  LL ma = 0;
  REP(i,0,s.size()){
    if(s[i]>=N){
      ma=max(ma,M/s[i]); 

    }
  }
  cout<<ma<<endl;


  return 0;
}
