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
// LL Sum(int now, list<int> rem) {
//   for (auto &e : rem) {
//     auto oldrem = rem;

//     Sum(now + 1, rem[i])
//   }
// }
double Dist(VEC<int> &seq, VEC<pair<int, int>> &P) {
  double sum = 0;
  int curx = P[seq[0]].first;
  int cury = P[seq[0]].second;
  REP(i, 1, seq.size()) {
    int nx = P[seq[i]].first;
    int ny = P[seq[i]].second;
    sum += sqrt(pow(nx - curx, 2) + pow(ny - cury, 2));
  }
  return sum;
}

int main() {
  int N;
  cin>>N;
  VEC<pair<int, int>> P(N);
  REP(i, 0, N) { cin >> P[i].first >> P[i].second; }
  VEC<int> seq(N);
  double sum = 0;
  int k=0;
  REP(i, 0, N) { seq[i] = i; }
  do {
    sum+=Dist(seq, P);
    k++;
  } while (next_permutation(ALL(seq)));
  printf("%.10lf\n", sum/k);

  return 0;
}
