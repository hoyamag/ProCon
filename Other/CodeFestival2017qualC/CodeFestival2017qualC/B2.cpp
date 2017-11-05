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
//#include<map>
//#include<set>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<unsigned long long>a(n, 0);
//	for (int i = 0; i < n; i++)cin >> a[i];
//	int even = 0, odd = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] % 2 == 0)even++;
//		else odd++;
//	}
//	unsigned long long sum = 0;
//	//sum = even*(unsigned long long)pow(3, n - 1) + odd*(unsigned long long)pow(2, even + 1);
//	int feven = 0; int  fodd = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] % 2== 0) {
//			sum += (unsigned long long)pow(3, n - 1 - i)* (unsigned long long)pow(2, feven);
//			feven++;
//		}
//		else {
//			sum += 2*(unsigned long long)pow(3, n - 1 - i)* (unsigned long long)pow(2,  feven);
//		}
//	}
//	cout << sum;
//	return 0;
//}
//
//
//
