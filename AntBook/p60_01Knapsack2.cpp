#include <algorithm>
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
#include <stdio.h>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(t) t.begin(), t.end()

ll Knapsack01_2(vector<ll> w, vector<ll> v, ll W)
{
    int n = w.size();
    int V = 0;
    ll inf = 1;
    inf<<=62;
    rep(i, n) V += v[i];
    vector<vector<ll>> dp(n+1, vector<ll>(V+1, inf));
    dp[0][0] = 0;
    cout<<"W = "<<W<<endl;
    cout<<"V = "<<V<<endl;
    cout<<"inf = "<<inf<<endl;
    for(int i = 0;i < n;i++){
        for (int j = 0; j <= V; j++) {
            dp[i + 1][j] = min(dp[i][j], j - v[i] >= 0 ? dp[i][j - v[i]] + w[i] : inf);
        }
    }
    ll ans =0;
    rep(j,V+1){
        if(dp[n][j]<=W) ans = j;
        cout<<"dp[n]["<<j<<"] = "<<dp[n][j]<<endl;
    }
    rep(i,dp.size()){
        rep(j,dp[i].size()){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}

int main()
{
    cout << Knapsack01_2({ 2, 1, 3, 2 }, { 3, 2, 4, 2 }, 5) << endl;

    return 0;
}
