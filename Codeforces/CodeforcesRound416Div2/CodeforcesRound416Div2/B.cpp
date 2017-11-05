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
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	s += 'A';
//	
//	int begin = 0;
//	list<string>subs(0);
//	for (int i = 0; i < s.size(); i++) {
//		if ('A' <= s[i] && s[i] <= 'Z') {
//			if (i - begin > 0) subs.push_back(s.substr(begin, i - begin));
//			begin = i + 1;
//		}
//	}
//
//	if (subs.empty()) {
//		cout << 0;
//		return 0;
//	}
//	vector<int>len(subs.size(), 0);
//	int subsindex = 0;
//	for (string su : subs) {
//		vector<int> cnt(26, 0);
//		for (int i = 0; i < su.size(); i++)cnt[su[i] - 'a']++;
//		for (int i = 0; i < 26; i++) if (cnt[i] != 0)len[subsindex]++;
//		subsindex++;
//	}
//	cout << *max_element(len.begin(), len.end());
//
//	return 0;
//}
//
//
//
