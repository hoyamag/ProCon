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
#include<stack>
using namespace std;
#define ul unsigned long long

#define rep(a, b) for(int i = a; i < b; i++)



int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;

	int sp = 0;
	int leftBrace = 0;
	int rightBrace = 0;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c =='(') {
			sp++;
		}
		else {
			if (sp <= 0) {
				leftBrace++;
			}
			else {
				sp--;
			}
		}
		
	}
	if (sp > 0) {
		rightBrace = sp;
	}
	//else if(sp<0) {
	//	leftBrace += sp;
	//}
	string l = "";
	rep(0, leftBrace) {
		l += "(";
	}
	string r = "";
	rep(0, rightBrace) {
		r += ")";
	}
	cout << l + s + r << endl;

	return 0;
}



