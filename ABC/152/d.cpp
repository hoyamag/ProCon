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
int N;
int diff(string a, string b) {
  if (a.length() != b.length()) {
    return 3;
  }
  int A = stoi(a);
  int B = stoi(b);
  return abs(A - B);
}

LL Max(int head, int tail) {
  DUMP("Max", head, tail);
  if (head == 0 || tail == 0) return 0;

  LL count = 0;
  if (head == tail) count++;

  if (10 * head + tail <= N) {
    count++;
  }
  string strN = to_string(N);
  if (100 * head + tail <= N) {
    REP(keta, 1, 8) {
      string lb = string(keta, '0');
      string ub = string(keta, '9');
      // DUMP("lb ub", lb, ub);
      while (diff(lb, ub) > 1) {
        int mid = (stoi(lb) + stoi(ub)) / 2;
        string smid = to_string(mid);
        // DUMP("lb,ub,mid, smid", lb, ub, mid, smid);
        smid = string(keta - smid.length(), '0') + smid;
        if (smid <= strN) {
          lb = smid;
        } else {
          ub = smid;
        }
      }
      count += stoi(lb) + 1;
      DUMP("keta, count, lb", keta, count, lb);
    }
    // int ok = 0;
    // int ng = N;
    // while (abs(ok - ng) > 1) {
    //   int mid = (ok + ng) / 2;
    //   string f = to_string(head) + to_string(mid) + to_string(tail);
    //   DUMP(head, tail, f);
    //   // DUMP(to_string(head) + to_string(mid) + to_string(tail));
    //   // DUMP(f);
    //   if (f <= strN) {
    //     ok = mid;
    //   } else {
    //     ng = mid;
    //   }
    // }
    // DUMP("    ", ok, ng);
    // count += ok;
  }
  // DUMP("  in Max", count);
  return count;
}

int main() {
  cin >> N;
  LL cnt = 0;
  VEC<VEC<int>> P(10, VEC<int>(10, 0));
  REP(h, 0, 10) {
    REP(t, 0, 10) { P[h][t] = Max(h, t); }
  }
  REP(a, 1, N + 1) {
    string sa = to_string(a);
    int h = sa[0] - '0';
    int t = sa[sa.length() - 1] - '0';
    swap(h, t);
    // DUMP(a, h, t, cnt);

    cnt += P[h][t];
  }
  cout << cnt << endl;

  return 0;
}
