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
class DisjointSet {
 public:
  DisjointSet *parent;
  long long rank;
  long long number;
  DisjointSet(long long x) {
    parent = this;
    this->number = x;
    this->rank = 0;
  }
  string to_string() {
    stringstream ss;
    ss << "this: " << this << ", parent: " << parent << ", number: " << number
       << ", rank: " << rank;
    return ss.str();
  }
};
void link(DisjointSet &x, DisjointSet &y) {
  if (x.rank > y.rank) {
    y.parent = &x;
  } else {
    x.parent = &y;
    if (x.rank == y.rank) ++y.rank;
  }
}
DisjointSet &find_set(DisjointSet &x) {
  if (x.parent != &x) {
    x.parent = &find_set(*x.parent);
  }
  return *x.parent;
}
ostream &operator<<(ostream &os, DisjointSet a) {
  return (os << a.to_string());
}
void unite(DisjointSet &x, DisjointSet &y) { link(find_set(x), find_set(y)); }

int main() {
  DisjointSet a(-1), b(-2);
  cout << a << endl;
  cout << b << endl;
  cout << endl;

  VEC<DisjointSet> A;
  cout << "Vec addr: " << &A << endl;
  REP(i, 0, 10) {
    // A.push_back(*new DisjointSet(i));
    A.push_back(DisjointSet(i));
    cout << A[i] << endl;
    cout << "Addr A[i]: " << &A << ", A[i]: " << A[i] << endl;
  }
  cout << endl;

  //   A[5].rank=5;
  //   A[5].parent=0;
  REP(i, 0, 10) { cout << A[i] << endl; }
  unite(A[0], A[1]);
  cout << endl;
  unite(A[1], A[2]);
  unite(A[3], A[4]);
  unite(A[5], A[6]);
  unite(A[0], A[6]);
  REP(i, 0, 10) { cout << A[i].to_string() << endl; }

  return 0;
}