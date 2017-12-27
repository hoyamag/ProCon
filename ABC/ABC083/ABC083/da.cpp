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
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()


int main() {
	string s;
	cin >> s;
	int n = s.length();
	int mi = 1 << 30;
	bool isSame = true;
	rep(i, n - 1) {
		if (s[i] != s[i + 1]) {
			isSame = false;
			mi = min(mi, max(i + 1, n - (i + 1)));
		}
	}
	isSame ? mi = n : mi;
	cout << mi << endl;
	return 0;
}



