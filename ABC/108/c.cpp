#include <algorithm>
#include <bitset>
#include <cstdio>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
#define DBG(str...)       \
    for (auto v : str)    \
        cerr << v << " "; \
    cerr << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;

int main()
{
    LL n, k;
    cin >> n >> k;
    LL ans = 0;
    REPC(a, 1, n)
    {
        LL aa = a;

        LL arem = a % k;
        LL b = k - arem;
        LL c = k - arem;
        if ((b + c) % k == 0)
        {
            LL num = (n - b ) / k+1;
            ans += num * num;
            DBG({ans, aa, b, c, num});
        }
    }
    cout << ans << endl;

    return 0;
}