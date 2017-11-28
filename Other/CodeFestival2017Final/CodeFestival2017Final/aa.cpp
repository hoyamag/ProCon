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
//#include<initializer_list>
//#include<map>
//#include<set>
//#include<utility>
//#include<tuple>
//#include<regex>
//using namespace std;
//#define ull unsigned long long
//#define llong long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define all(t) t.begin(), t.end()
//
//string akiba(string s) {
//	vector<string> can = {
//		"KIHBR",
//		"KIHBRA",
//		"KIHBAR",
//		"KIHBARA",
//		"KIHABR",
//		"KIHABRA",
//		"KIHABARA",
//		"AKIHBR",
//		"AKIHBRA",
//		"AKIHBAR",
//		"AKIHABR",
//		"AKIHABRA",
//		"AKIHABAR",
//		"AKIHABARA" };
//	auto it = find(all(can), s);
//	if (it != can.end())return "YES";
//	else return "NO";
//}
//string akiba2(string s) {
//	string s2(s);
//	s2 = string(s2.begin(), remove(all(s2), 'A'));
//	if (s2 != "KIHBR") return "NO";
//	if (s.find("KIH") == string::npos) return "NO";
//	int n = s.length();
//	rep(i, n - 1) if (s[i] == s[i + 1])return "NO";
//	return "YES";
//}
//string akiba3(string s) {
//	regex reg("A?KIHA?BA?RA?");
//	return regex_match(s, reg) ? "YES" : "NO";
//
//}
//int main() {
//	string s;
//	cin >> s;
//	cout << akiba3(s) << endl;
//	return 0;
//}
//
//
//
