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
//#include<utility>
//#include<initializer_list>
//#include<tuple>
//#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
bool isSubstring(string substr, string t) {
	int n = substr.length();
	int seek = 0;
	rep(i, n) {
		bool ex = 0;
		for (int j = seek; j < t.length(); j++) {
			if (substr[i] == t[j]) {
				ex = 1;
				seek = j + 1;
				break;
			}
		}
		if (ex) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;

}

int LongestCommonSubstring(string s, string t) {
	// Wrong plan
	vector<int>dp(s.length(), 0);
	int n = s.length();
	string lcs = "";
	if (isSubstring(s.substr(n - 1, n), t)) {

		dp[n - 1] = 1;
		lcs = s[n - 1];
	}
	for (int i = n - 2; i >= 0; i--) {
		//string substr = s.substr(i, n);
		string substr = s[i] + lcs;
		int issubst = isSubstring(substr, t);
		if (issubst) lcs = substr;
		dp[i] = dp[i + 1] + issubst;
	}
	return dp[0];
}
int LongestCommonSubstring2(string s, string t) {
  // AC AOJ ALDS1_10_C
  // return
  //  the length of longest common subsequence of s and t.
  //    subsequence of string s is s[i1]+s[i2]+...+s[ik] (i1<i2<...<ik)
	vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
	int n = s.length() + 1;
	int m = t.length() + 1;
	rep(i, n - 1) {
		rep(j, m - 1) {
			dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	return dp[n - 1][m - 1];
}
int main() {
	//cout << isSubstring("abc", "abcde") << endl;
	//cout << isSubstring("bd", "abcde") << endl;
	//cout << isSubstring("db", "abcde") << endl;

	//cout << LongestCommonSubstring2("bacd", "becd") << endl;
	//cout << LongestCommonSubstring2("abcd", "becd") << endl;
	//cout << endl;
	//cout << LongestCommonSubstring2("a", "a") << endl;
	//cout << LongestCommonSubstring2("bbb", "bbb") << endl;
	//cout << LongestCommonSubstring2("aba", "bbaba") << endl;
	//cout << LongestCommonSubstring2("abababbbaa", "bbabaabba") << endl;
	//cout << LongestCommonSubstring2("a", "aaaaa") << endl;
	//cout << LongestCommonSubstring2("aizojfeiz", "aaaizojifeizz") << endl;
	//cout << LongestCommonSubstring2("zzyiioxizu", "zzsyoizuo") << endl;
	//cout << LongestCommonSubstring2("iooooioiooiio", "ooiiioioiooooiioio") << endl;
	//cout << LongestCommonSubstring2("ajfoaooieellzljieoaelj", "ajoiiffoaolliseellzljieoaelj") << endl;
	//cout << LongestCommonSubstring2("zzzzzyyzyy", "zzyyyyz") << endl;
	//cout << LongestCommonSubstring2("abcdef", "fedcba") << endl;
	//cout << LongestCommonSubstring2("abc", "xyz") << endl;
	int q;
	cin >> q;
	vector<string> s(q);
	vector<string> t(q);
	rep(i, q) {
		cin >> s[i] >> t[i];
	}
	rep(i, q) {
		cout << LongestCommonSubstring2(s[i], t[i]) << endl;
	}

	return 0;
}



