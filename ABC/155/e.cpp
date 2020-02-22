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
  cerr << setw(5) << head << ", ";
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
LL ANS = 0;
map<int, int> Alpha;
string Num2Str(int num) {
  string s = "";
  while (num > 0) {
    s.push_back(num % 10 + '0');
    num /= 10;
  }
  reverse(ALL(s));
  return s;
}
int Str2Num(string s) {
  int sum = 0;
  int k = 1;
  for (int i = s.length() - 1; i >= 0; i--) {
    sum += (s[i] - '0') * k;
    k *= 10;
  }
  return sum;
}
LL Count(string s) {
  int n = s.length();
  LL sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    int k = s[i] - '0';
    sum += k;
  }
  return sum;
}
string Next(string s, int keta) {
  // 1の位がs[0]
  int n = s.length();
  // Alpha[keta]++;
  string ret = s;
  // DUMP("Next", s, keta);
  if (keta == (int)s.length()) {
    if (n > 1) {
      return s.substr(0, n - 1) + "01";

    } else
      return "01";
  }

  int k = s[keta] - '0';
  if (k != 9) {
    ret[keta] = k + 1 + '0';
    return ret;
  } else {
    ANS -= 7;
    ret[keta] = '0';
    return Next(ret, keta + 1);
  }
}
string KetaUp(string s, int keta) {
  // 1の位がs[0]
  s[keta] = '0';
  s = Next(s, keta + 1);
  return s;
}

int main() {
  string N;
  cin >> N;
  // ANS = Count(N);

  // int n = Str2Num(N);
  // REP(i, n, n + 100) {
  //   int inum = Count(Num2Str(i));
  //   int back = i - n;
  //   int bnum = Count(Num2Str(back));
  //   DUMP(i, inum, back, bnum, "sum:", inum + bnum);
  // }

  string M = N;
  reverse(ALL(M));
  // DUMP(M);
  REP(i, 0, M.length()) {
    // REP(j, 0, i) { cerr << " "; }
    // cerr << "." << endl;
    // cerr << M << " " << i << " ANS:" << ANS << endl;
    int num = M[i] - '0';
    if (6 <= num && num <= 9 ) {
      // ANS -= (num - 6) * 2 + 1;
      Alpha[i] += 10 - num;
      // DUMP(M, i);
      M = KetaUp(M, i);
      // DUMP(M);
    }
  }
  // cout << ANS << endl;
  LL ans = Count(M);
  for(auto v:Alpha){
    ans+=v.second;
  }
  cout<<ans<<endl;

  return 0;
}

// string Next(string s, int keta) {
//   int n = s.length();
//   string ret = s;
//   // DUMP("Next", s, keta);
//   if (keta == -1) {
//     if (n > 1) {
//       return "10" + s.substr(1, n - 1);

//     } else
//       return "10";
//   }

//   int k = s[keta] - '0';
//   if (k != 9) {
//     ret[keta] = k + 1 + '0';
//     return ret;
//   } else {
//     ret[keta] = '0';
//     return Next(ret, keta - 1);
//   }
// }