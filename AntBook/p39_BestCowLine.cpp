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
//#include<initializer_list>
#include<map>
#include<set>
//#include<utility>
//#include<tuple>
using namespace std;
#define ull unsigned long long
#define llong long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
string BestCowLine(string s) {
	//POJ3617 my solution(but I've forgotten boudary)
	//s : string, all upper case.
	//return : the smallest string in dictionary order out of such operation.
	//	* take head of s as tail of return string and erase it from s
	//	or * take tail of s as tail of return string and erase it from s
	int n = s.length();
	string t;
	int lh = 0, rh = n - 1;

	rep(i, n) {
		if (s[lh] < s[rh]) {
			t.push_back(s[lh]);
			lh++;

		}
		else if (s[lh] > s[rh]) {
			t.push_back(s[rh]);
			rh--;
		}
		else {
			int tlh = lh;
			int trh = rh;
			while (trh > tlh && s[tlh] == s[trh]) {
				tlh++;
				trh--;
			}
			if (s[tlh] < s[trh]) {
				t.push_back(s[lh]);
				lh++;
			}
			else {
				t.push_back(s[rh]);
				rh--;
			}
		}
	}
	return t;
}
string BestCowLine2(string s) {
	//POJ3617 solution by the book
	//s : string, all upper case.
	//return : the smallest string in dictionary order out of such operation.
	//	* take head of s as tail of return string and erase it from s
	//	or * take tail of s as tail of return string and erase it from s
	int n = s.length();
	string t;
	int i, r;
	i = r = 0;
	while (i + r < n) {
		string ss(s.begin() + i, s.end() - r);
		string sr(s.rbegin() + r, s.rend() - i);
		if (ss < sr) {
			t.push_back(ss[0]);
			i++;
		}
		else {
			t.push_back(sr[0]);
			r++;
		}
	}
	return t;
}
int main() {
	int n;
	cin >> n;
	string s;
	rep(i, n) {
		char t;
		cin >> t;
		s.push_back(t);
	}
	string t = BestCowLine2(s);
	rep(i, n) {
		if (i != 0 && i % 80 == 0)printf("\n");
		printf("%c", t[i]);
	}
	printf("\n");
	return 0;
}



