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
//string ans;
//
//bool dfs(vector<int> a, string op, int sum) {
//
//	if (a.size() == 1) {
//		return sum == a[0];
//	}
//	else {
//		vector<int> sub(a.begin() + 1, a.end());
//		int newsum = op == "+" ? sum - a[0] : sum + a[0];
//		bool res1 = dfs(sub, "+", newsum);
//		if (res1) return true;
//		bool res2 = dfs(sub, "-", newsum);
//		return res2;
//	}
//
//}
//int main() {
//	string s;
//	cin >> s;
//	int a, b, c, d;
//	a = s[0];
//	b = s[1];
//	c = s[2];
//	d = s[3];
//
//	return 0;
//}
//
//
//
