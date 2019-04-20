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

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  VEC<int> C(N);
  REP(i, 0, N) {
    if (S[i] == '1')
      C[i] = 1;
    else
      C[i] = 0;
  }
  VEC<pair<int, int>> Combo;
  int b = 0;
  DUMP(C);
  REP(i, 0, N) {
    if (i + 1 < N && C[i] == C[i + 1]) {
      continue;
    } else {
      Combo.push_back(make_pair(C[i], i - b + 1));
      b = i + 1;
    }
  }
  if (K >= Combo.size()) {
    cout << N << endl;
    return 0;
  }
  DUMP(Combo);

  int zeros = 0;
  int cnt = 0;
  int right = Combo.size();
  REP(i, 0, Combo.size()) {
    if (Combo[i].first == 0) ++zeros;
    if (zeros > K) {
      right = i;
      break;
    }
    cnt += Combo[i].second;
  }
  int ans = cnt;
  // DUMP(0, right, cnt);
  REP(left, 1, Combo.size()) {
    if (Combo[left].first == 0) {
      if (left - 1 >= 0) cnt -= Combo[left - 1].second;
    } else {
      if (left - 1 >= 0) cnt -= Combo[left - 1].second;
      if (right < Combo.size())
        cnt += Combo[right].second;
      if (right + 1 <= Combo.size() )
        cnt += Combo[right+1].second;
      right += 2;
    }
    // DUMP(left, right, cnt);
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}
