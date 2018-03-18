//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
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
//#define rep(i, n) for(i=0;i<(int)(n);i++)
//#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
//#define all(t) t.begin(), t.end()
//#define rall(t) t.rbegin(), t.rend()
//#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
//#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
//#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
//int main() {
//	int n;
//	cin >> n;
//	vector<string>s(n);
//	map<char, int> m;
//	int i;
//	rep(i, n) {
//		cin >> s[i];
//		m[s[i][0]]++;
//	}
//	ull sum = 0;
//
//	vector<int>b(5, 0);
//	vector<char> cc = { 'M', 'A', 'R', 'C', 'H' };
//	int d = 0;
//
//	rep(b[0], 2) {
//		if (b[0] == 1 && m['M'] == 0)continue;
//
//		rep(b[1], 2) {
//			if (b[1] == 1 && m['A'] == 0)continue;
//			rep(b[2], 2) {
//				if (b[2] == 1 && m['R'] == 0)continue;
//				rep(b[3], 2) {
//					if (b[3] == 1 && m['C'] == 0)continue;
//					rep(b[4], 2) {
//						if (b[4] == 1 && m['H'] == 0)continue;
//						int ssum = 0;
//						int aaa;
//						rep(aaa, 5)ssum += b[aaa];
//
//						if (ssum == 3) {
//							ull tmp = 1;
//							int bbb;
//							rep(bbb, 5) if (b[bbb] != 0 && m[cc[bbb]] != 0)tmp *= (ull)b[bbb] * (ull)m[cc[bbb]];
//							sum += tmp;
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << sum;
//
//	return 0;
//}
//
//
//
