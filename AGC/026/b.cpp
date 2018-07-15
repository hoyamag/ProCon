#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
#define DBG(str) cerr<<(str)<<endl;
int main() {
	int t;
	cin >> t;
	vector<ll>A(t), B(t), C(t), D(t);
	rep(i, 0, t) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	rep(i, 0, t) {
		bool yes = true;
		ll a = A[i];
		ll b = B[i];
		ll c = C[i];
		ll d = D[i];
		if (d < b || a < b)yes = false;
		else if (a%b > c)yes = false;
		else if (d - b == 0) {
			if (a%b <= c)yes = 1;
			else yes = false;
		}
		else if (c >= b)yes = true;
		else {
			ll rm = (c - (a - b)) % (d - b);
			if (c - rm + (d - b) < b)yes = false;
			//else {
				//if (d - b != 0) {
				//	double xx = (double)(c + d - b - (a - b)) / (d - b);
				//	ll x = xx;
				//	cerr << x << endl;
				//	cerr << a%b << endl;
				//	if ((a - b) + x*(d - b) >= b)yes = 1;
				//	else yes = false;
				//}
				//else {
				//	if (a%b <= c)yes = 1;
				//	else yes = false;
				//}

		//}
		}
		Yes(yes);
	}
	return 0;
}



