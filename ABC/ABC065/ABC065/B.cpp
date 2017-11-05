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
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a = vector<int>(n, 0);
//	rup(i, 0, n) {
//		cin >> a[i];
//		a[i]--;
//	}
//	vector<bool> already = vector<bool>(n, 0);
//
//	int search = a[0];
//	already[0] = true;
//	int count = 1;
//	while (1) {
//		int next;
//
//		if (search == 1) {
//			cout << count;
//			break;
//		}
//		else {
//			if (!already[search]) {
//				already[search] = true;
//				next = a[search];
//				count++;
//			}
//			else {
//				cout << -1;
//				break;
//			}
//		}
//		search = next;
//	}
//
//	return 0;
//}
//
//
//
