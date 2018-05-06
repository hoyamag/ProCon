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
//int main() {
//	int h, w;
//	cin >> h >> w;
//	auto s = mat(char,h+2, w+2, '.');
//	rep(i, 0, h)rep(j,0,w)cin >> s[i+1][j+1];
//	
//	bool ng = false;
//
//	rep(i, 0, h) {
//		rep(j, 0, w) {
//			if (s[i][j] == '#') {
//				char c = '.';
//				int d = 0;
//				if (s[i + 1][j] == c)d++;
//				if (s[i - 1][j] == c)d++;
//				if (s[i][j + 1] == c)d++;
//				if (s[i][j - 1] == c)d++;
//				if (d == 4)ng = 1;
//			}
//
//		}
//	}
//	Yes(!ng);
//
//	return 0;
//}
//
//
//
