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
#include<map>
#include<set>
using namespace std;

int main() {
	string s;
	cin >> s;
	int b = 0;
	int e = s.length() - 1;
	int x = 0;
	while (b < e) {
		if (s[b] == s[e]) {
			b++;
			e--;
		}
		else {
			if (s[b] == 'x') {
				b++;
				x++;
			}
			else if (s[e] == 'x') {
				e--;
				x++;
			}
			else{
				cout << -1;
				return 0;
			}
		}

	}
	cout << x;
	return 0;
}



