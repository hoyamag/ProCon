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
ostream &operator<<(ostream &os, list<T> &vec) {
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
int N, A, B, C, D;
VEC<int> a;
VEC<int> b;
VEC<int> c;
VEC<int> d;
list<int> ans;

bool dfs(VEC<int> I, VEC<int> remain) {
  int xa = a[I[0]];
  int xb = b[I[1]];
  int xc = c[I[2]];
  int xd = d[I[3]];
  // DUMP(I, remain, xa, xb, xc, xd, ans);
  if (ans.size() == N-1) {
    for (auto v : ans) {
      cout << v << endl;
    }
    for(int i=0;i<4;++i){
      if(remain[i]>0)cout<<i+1<<endl;
    }
    return 1;
  }
  VEC<int> E = {xa, xb, xc, xd};
  REP(i, 0, 4) {
    REP(j, i + 1, 4) {
      if (E[i] == E[j]) {
        REP(k, 0, 4) I[k]++;
        I[i]--;
        remain[i]--;
        ans.push_back(i + 1);
        if (remain[i] >= 0) {
          if (dfs(I, remain)) return 1;
        }
        I[i]++;
        remain[i]++;
        ans.pop_back();

        I[j]--;
        remain[j]--;
        ans.push_back(j + 1);
        if (remain[j] >= 0) {
          if (dfs(I, remain)) return 1;
        }
        I[j]++;
        remain[j]++;
        ans.pop_back();
        return 0;
      }
    }
  }
  return 0;
}

int main() {
  cin >> N >> A >> B >> C >> D;
  a = VEC<int>(N);
  b = VEC<int>(N);
  c = VEC<int>(N);
  d = VEC<int>(N);
  VEC<int> cnt(5, 0);
  REP(i, 0, A) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  cnt[4] += N - A;

  REP(i, 0, B) {
    cin >> b[i];
    cnt[b[i]]++;
  }
  cnt[4] += N - B;

  REP(i, 0, C) {
    cin >> c[i];
    cnt[c[i]]++;
  }
  cnt[4] += N - C;

  REP(i, 0, D) {
    cin >> d[i];
    cnt[d[i]]++;
  }
  cnt[4] += N - D;

  bool all = 1;
  REP(i, 1, 5) {
    if (cnt[i] != N) all = 0;
  }
  if (!all) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  dfs({0, 0, 0, 0}, {N - A, N - B, N - C, N - D});

  return 0;
}
