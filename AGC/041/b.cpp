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
// bool isPossible(LL target, int V, LL M, VEC<LL> &C) {
//   // isPossible? max(C) is less than or equal target.
//   // DUMP("isPossible", target, V, M, C);
//   if (V == 0) {
//     return C[0] <= target;
//   }
//   if (C[0] > target) {
//     return false;
//   }
//   priority_queue<LL, VEC<LL>, greater<LL>> pq;
//   REP(i, 0, C.size()) { pq.push(C[i]); }
//   LL cnt = 0;
//   LL prev = 0;
//   while (cnt < M) {
//     VEC<LL> tmp;
//     LL ma = 0;
//     REP(i, 0, V) {
//       LL a = pq.top();
//       pq.pop();
//       tmp.push_back(a);
//       ma = max(ma, a);
//     }
//     // //DUMP("isPossible loop", cnt, pq.top(), tmp);
//     if (ma > target) {
//       return false;
//     }
//     cnt += (target - ma);
//     if (cnt >= M) break;
//     REP(i, 0, tmp.size()) {
//       tmp[i] += target - ma;
//       pq.push(tmp[i]);
//     }
//     if (cnt == prev) {
//       return false;
//     }
//     prev = cnt;
//   }
//   return true;
// }
// LL ProbT(LL N, LL M, LL V, VEC<LL> &C) {
//   // return value
//   // DUMP("ProbT", N, M, V, C);
//   LL possi = 1e9 + 1;
//   LL cant = 0;
//   while (possi - cant > 1) {
//     LL mid = (possi + cant) / 2;
//     if (isPossible(mid, V, M, C)) {
//       // DUMP("ProbT", mid, "is possible");
//       possi = mid;
//     } else {
//       // DUMP("ProbT", mid, "is not possible");
//       cant = mid;
//     }
//   }
//   return possi;
// }
bool isPossible(LL X, LL N, LL M, LL V, LL P, VEC<LL> &A) {
  if (X <= P) {
    return true;
  }
  if(A[X]+M<A[P]){
    return false;
  }
  int modV = V - (P - 1) - (N - X);
  if (modV <= 0) {
    return true;
  }
  return false;
}

int main() {
  LL N, M, V, P;
  cin >> N >> M >> V >> P;
  P--;
  VEC<LL> A(N);
  REP(i, 0, N) cin >> A[i];
  sort(ALL(A), greater<LL>());

  int deru = P, denai = N;
  // DUMP("HI");
  while (denai - deru > 1) {
    // DUMP("Main loop", deru, denai);
    int mid = (deru + denai) / 2;
    LL subs = isPossible(mid, N, M, V, P, A);
    if (A[mid] + M >= subs) {
      deru = mid;
      // cerr << "Main loop, " << A[mid] << " is possible" << endl;
    } else {
      denai = mid;
      // cerr << "Main loop, " << A[mid] << " is not possible" << endl;
    }
  }
  // DUMP("");
  // REP(i, 0, N) {
  //   LL subs = ProbS(i, N, M, V, P, A);
  //   if (A[i] + M >= subs) {
  //     // cerr << "Main loop, " << A[i] << " is possible" << endl;
  //   } else {
  //     // cerr << "Main loop, " << A[i] << " is not possible" << endl;
  //   }
  // }
  cout << deru + 1 << endl;

  return 0;
}
