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
int N, K;
VEC<int> A;
std::mt19937 MT(15);

int randInRange(int minimum, int maximum) {
  return minimum + MT() % (maximum - minimum + 1);
}
int minInRange(int s, int e) {
  int mi = INT32_MAX;
  REPC(i, s, e) mi = min(mi, A[i]);
  return mi;
}
int maxInRange(int s, int e) {
  int ma = INT32_MIN;
  REPC(i, s, e) ma = max(ma, A[i]);
  return ma;
}
void update(int i, int j, int k, int l, int v) {
  REPC(a, i, j) A[a] -= v;
  REPC(a, k, l) A[a] += v;
}
int main() {
  cin >> N >> K;
  A = VEC<int>(N + 1, -1);
  REPC(i, 1, N) cin >> A[i];
  REP(c, 0, K) {
    int i = randInRange(1, N - 1);
    int k = randInRange(i + 1, N);
    int maxlength = min(k - i - 1, N - k);
    int length = randInRange(0, maxlength);
    int j = i + length;
    int l = k + length;
    int left = minInRange(i, j) - 1;
    int right = N - maxInRange(k, l);
    int vmax = min(left, right);
    int v = randInRange(0, vmax);
    update(i, j, k, l, v);
    cout << i << " " << j << " " << k << " " << l << " " << v << endl;

    // DUMP(maxlength,length, left, right, vmax);
    //REPC(d, 1, N) {
      //if (A[d] <= 0 || A[d] > N) {
        //cout << "ILLEGAL" << endl;
        //DUMP(A);
        //DUMP(d, A[d]);
        //return 0;
      //}
    //}
    //if (i > j || k > l || j - i != l - k) {
      //cout << "illegal!" << endl;
    //}
    // DUMP(A);
    // DUMP(maxlength, left, right, vmax, A);
  }

  return 0;
}
