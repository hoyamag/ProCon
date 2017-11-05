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


int main() {
	int h, w;
	cin >> h >> w;
	vector<string>t(h, "");
	for (int i = 0; i < h; i++) {
		cin >> t[i];
	}
	int g1 = (h*w) % 2;
	int g2 = (w / 2) * (h % 2) + (h / 2) * (w % 2);
	int g4 = (h / 2) * (w / 2);
	vector<int>c(26, 0);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			c[t[i][j] - 'a'] ++;
		}
	}
	// WA‚Á‚Ä‚é‚Ì‚Å‰º‹L‚Ì1,2,4‚Ì‡”Ô‚ðŽ¡‚·B
	for (int i = 0; i < g1; i++) {
		for (int j = 0; j < 26; j++) {
			if (c[j] % 4 == 1 || c[j] % 4 == 3) {
				c[j]--;
				break;
			}
		}
	}
	for (int i = 0; i < g2; i++) {
		for (int j = 0; j < 26; j++) {
			if (c[j] % 4 == 2) {
				c[j] -= 2;
				break;
			}
		}
	}
	for (int i = 0; i < g4; i++) {
		for (int j = 0; j < 26; j++) {
			if (c[j] != 0 && c[j] % 4 == 0) {
				c[j] -= 4;
				break;
			}
		}
	}
	if (*max_element(c.begin(), c.end()) == 0) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}



