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
#define ul unsigned long long

#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

int main() {
	string s;
	cin >> s;
	string str = s;
	int wholeResult = INT_MAX;
	rup(loopCount, 0, str.length()) {
		int result = 0;
		char same = str[loopCount];

		s = str;
		int iteration = 0;
		while (1) {
			//judge
			int count = 0;
			rup(i, 0, s.length() - iteration) {
				if (s[i] == same) count++;
			}
			if (count == s.length() - iteration) break;
			result++;
		
			//change
			rup(i, 1, s.length()) {
				if (s[i] == same) {
					s[i - 1] = same;
				}

			}
			iteration++;
		}
		if (result < wholeResult) wholeResult = result;
	}
	cout << wholeResult;
	return 0;
}



