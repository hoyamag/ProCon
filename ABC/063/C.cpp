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
//#define ul unsigned long long
//
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> s = vector<int>(n, 0);
//	for (int i = 0; i < n; i++) cin >> s[i];
//	
//	int sum = 0;
//	for (int i = 0; i < n; i++)sum += s[i];
//	
//	int max = 0;
//	if (sum % 10 == 0) {
//		sort(s.begin(), s.end());
//		for (int i = 0; i < n; i++) {
//			if (s[i] % 10 == 0) {
//				continue;
//			}
//			else {
//				max = sum - s[i];
//				break;
//			}
//		}
//	}
//	else {
//		max = sum;
//	}
//	cout << max << endl;
//
//	return 0;
//}
//
//
