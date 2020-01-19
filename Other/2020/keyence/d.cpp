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
int ans_cand = 0;
VEC<int> bub_sort_cnt(VEC<int> C, int rev) {
  int N = C.size();
  VEC<int> cnt(N, 0);
  VEC<int> index(N);
  REP(i, 0, N) { index[i] = i; }

  REP(i, 0, N) {
    REP(j, 0, N - i - 1) {
      if (C[j] > C[j + 1]) {
        swap(index[j], index[j + 1]);
        swap(C[j], C[j + 1]);
        cnt[index[j]]++;
        cnt[index[j + 1]]++;
        ans_cand++;
      }
    }
  }

  // DUMP("  ", C, cnt);
  // fix
  REP(i, 0, N - 1) {
    int expect = (rev >> i) & 1;
    int actual = cnt[i] % 2;
    if (expect != actual && C[i] == C[i + 1]) {
      cnt[index[i]]++;
      cnt[index[i + 1]]++;
    }
  }
  return cnt;
}
VEC<bool> gOK;
bool verify(VEC<int> &C, VEC<int> &cnt, int rev) {
  int N = cnt.size();
  VEC<bool> ok(N, 0);
  REP(i, 0, N) {
    int expect = (rev >> i) & 1;
    int actual = cnt[i] % 2;
    ok[i] = (expect == actual);
  }
  gOK = ok;
  REP(i, 0, N) {
    if (!ok[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int N;
  cin >> N;
  VEC<int> A(N), B(N);
  REP(i, 0, N) cin >> A[i];
  REP(i, 0, N) cin >> B[i];
  VEC<int> C(N, 0);
  int mi = INT32_MAX;
  VEC<bool> rev_array(N, 0);
  REP(rev, 0, 1 << N) {
    REP(i, 0, N) {
      rev_array[i] = (rev >> i) & 1;
      if ((rev >> i) & 1) {
        C[i] = B[i];
      } else {
        C[i] = A[i];
      }
    }
    ans_cand = 0;
    auto cnt = bub_sort_cnt(C, rev);
    if (verify(C, cnt, rev)) {
      mi = min(mi, ans_cand);
    }
    // DUMP(rev, C, rev_array, cnt, gOK, mi);
  }
  cout << (mi == INT32_MAX ? -1 : mi) << endl;

  return 0;
}
