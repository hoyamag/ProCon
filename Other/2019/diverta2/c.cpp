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

int main() {
  int N;
  cin >> N;
  VEC<LL> A(N);
  REP(i, 0, N) cin >> A[i];
  sort(ALL(A));
  LL M = 0;
  LL sumA = 0;
  LL sumB = 0;
  REP(i, 0, N) {
    if (i < N / 2) {
      sumA += -A[i];
    } else {
      sumA += A[i];
    }
  }
  REP(i, 0, N) {
    if (i <= N / 2) {
      sumB += -A[i];
    } else {
      sumB += A[i];
    }
  }
  int div = 0;
  bool leftBig = 0;
  M = max(sumA, sumB);
  if (sumA >= sumB) {
    div = N / 2;
  } else {
    div = N / 2 + 1;
    leftBig = 1;
  }
  VEC<pair<int,int>> D(N);
  // DUMP(leftBig);
  if (leftBig) {
    int index = 0;
    for (int i = N; i > 0; i -= 2) {
      D[index] = {i,A[index]};
      index++;
    }
    index = N - 1;
    for (int i = N - 1; i > 0; i -= 2) {
      D[index] = {i,A[index]};
      index--;
    }
  } else {
    int index = N - 1;
    for (int i = N; i > 0; i -= 2) {
      D[index] = {i,A[index]};
      index--;
    }
    index = 0;
    for (int i = N-1; i > 0; i -= 2) {
      D[index] = {i,A[index]};
      index++;
    }
  }
  sort(ALL(D));
  DUMP(D);
  cout<<D[1].second<<" "<<D[0].second<<endl;
  int prev=D[1].second-D[0].second;
  REP(i,2,N){
    cout<<D[i].second<<" "<<prev<<endl;
    prev=D[i].second-prev;
  }

  cout << M << endl;
  return 0;
}
