#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
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
#include<bitset>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
int cnt(int a) {
	int s = 0;
	while (a > 0) {
		if (a & 1) s++;
		a >>= 1;
	}
	return s;
}
int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	vector<char>top = { 'M', 'A', 'R', 'C', 'H' };
	map<char, int>m;
	rep(i, n)m[s[i][0]]++;
	ll sum = 0;
	int mx = 0b100000;
	rep(b, mx) {
		if (cnt(b) == 3) {
			int tb = b;
			int j = 0;
			ll tsum = 1;
			while (tb > 0) {
				if (tb & 1) {
					tsum *= m[top[j]];
				}
				tb >>= 1;
				j++;
			}
			sum += tsum;
		}
	}
	cout << sum << endl;
	return 0;
}



