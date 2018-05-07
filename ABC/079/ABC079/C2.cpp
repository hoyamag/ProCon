//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
//#include<sstream>
//#include<list>
//#include<queue>
//#include <algorithm>
//#include<initializer_list>
//#include<map>
//#include<set>
//#include<utility>
//#include<tuple>
//using namespace std;
//int myeval(string s) {
//	int a = (int)s[0] - '0';
//	int b = (int)s[2] - '0';
//	int c = (int)s[4] - '0';
//	int d = (int)s[6] - '0';
//	int sum = a;
//	if (s[1] == '+') sum += b;
//	else sum -= b;
//	if (s[3] == '+') sum += c;
//	else sum -= c;
//	if (s[5] == '+') sum += d;
//	else sum -= d;
//	return sum;
//}
//bool dfs(string abcd, string op, string &res) {
//	string orig = res + op + abcd[0];
//	res = orig;
//	if (abcd.size() == 1) {
//		int e = myeval(res);
//		return e == 7 ;
//	}
//	else {
//		string sub(abcd.begin() + 1, abcd.end());
//		if(dfs(sub, "+", res)) return true;
//		res = orig;
//		return dfs(sub, "-", res);
//	}
//}
//
//int main() {
//	string s;
//	cin >> s;
//	string res(s.begin(), s.begin()+1);
//	string ans;
//	if (dfs(string(s.begin()+1, s.end()), "+", res)) ans = res;
//	else
//	{
//		res = string(s.begin(), s.begin() + 1);
//		if (dfs(string(s.begin()+1, s.end()), "-", res))ans = res;
//	}
//	cout << res + "=7"<<endl;
//	return 0;
//}
//
//
//
