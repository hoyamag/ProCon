#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include <algorithm>
#include<initializer_list>
using namespace std;
#define ul  unsigned long long

#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

string parse(vector<string> s) {
	// sを、並べ方のパターンを表したstring(例 : "XYYXXY")に分解し返す。
	// X pattern : 
	//	a
	//	a
	// Y pattern : 
	//	aa
	//	bb
	int n = s[0].size();
	string pattern = "";
	for (int i = 0; i < n; i++) {
		if (s[0][i] == s[1][i]) {
			pattern += "X";
		}
		else {
			pattern += "Y";
			i++;
		}
	}

	return pattern;
}

vector<int> numberOfCases(string pattern) {
	// 並べ方のパターンを表したstringを受け取り、各パターンでの色分けの場合の数をvectorに格納して返す
	int n = pattern.length();
	vector<int> cases = vector<int>(n);
	if (pattern[0] == 'X') {
		cases[0] = 3;
	}
	else {
		cases[0] = 6;
	}
	for (int i = 1; i < n; i++) {
		if (pattern[i-1] == 'X') {
			cases[i] = (pattern[i] == 'X') ? 2 : 2;
		}
		else {
			cases[i] = (pattern[i] == 'X') ? 1 : 3;
		}
	}
	return cases;

}
ul product(vector<int> caseNumbers) {
	// caseNumbersに格納された数をすべてかけ合わせる。なお計算結果はmod 1000000007 される
	const ul M = 1000000007;
	int n = caseNumbers.size();
	ul product = caseNumbers[0];
	for (int i = 1; i < n; i++) {
		product *= caseNumbers[i];
		product %= M;
	}
	return product;
}

int main() {
	int n;
	vector<string> s = vector<string>(2);
	cin >> n;
	cin >> s[0];
	cin >> s[1];
	string pattern = parse(s);
	vector<int> caseNumbers = numberOfCases(pattern);
	

	cout << product(caseNumbers);
	return 0;
}



