//#include<bitset>
//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstdio>
//#include<sstream>
//#include<list>
//#include<queue>
//#include<algorithm>
//#include<functional>
//#include<map>
//#include<set>
//#include<utility>
//#include<initializer_list>
//#include<tuple>
//#include<regex>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
//#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
//#define all(t) t.begin(), t.end()
//#define rall(t) t.rbegin(), t.rend()
//#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
//#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
//#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
//#define DBG(str) cerr<<(str)<<endl;
//int solve(vector<ll> v) {
//	int n = v.size();
//	priority_queue<ll, vector<ll>, greater<ll>>ev, odd;
//	rep(i, 0, n) {
//		ll a = v[i];
//		i % 2 == 0 ? ev.push(a) : odd.push(a);
//	}
//	int index = -1;
//	ll prev = -1;
//	rep(i, 0, n) {
//		ll cur;
//		if (i % 2 == 0) {
//			cur = ev.top();
//			ev.pop();
//		}
//		else {
//			cur = odd.top();
//			odd.pop();
//		}
//		if (cur < prev) {
//			index = i - 1;
//			break;
//		}
//		prev = cur;
//		DBG(cur);
//	}
//	return index;
//
//}
//int main() {
//	cin.sync_with_stdio(false);
//	int t;
//	cin >> t;
//	vector<int>n(t);
//	list<vector<ll>>v;
//	rep(i, 0, t) {
//		cin >> n[i];
//		vector<ll> tmp(n[i]);
//		rep(j, 0, n[i]) {
//			cin >> tmp[j];
//		}
//		v.push_back(tmp);
//	}
//
//	int i = 1;
//	for (auto vec : v) {
//		int index = solve(vec);
//		cout << "Case #" << i << ": ";
//		if (index == -1)cout << "OK" << endl;
//		else cout << index << endl;
//
//		i++;
//	}
//
//	return 0;
//}
//
//
//
