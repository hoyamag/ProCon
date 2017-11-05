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
//#define ll long long
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//
//double noudo(int a, int b) {
//	return 100 * b / (a + b);
//}
//
//int main() {
//	int a, b, c, d, e, f;
//	cin >> a >> b >> c >> d >> e >> f;
//	vector<double>noud(4, 0);
//	int s = 0;
//	int w = 0;
//	a = 100 * a;
//	b = 100 * b;
//	while (true) {
//		if (s + a + w + c <= f) {
//			noud[0] = noudo(s + a, w + c);
//		}
//		else if (s + a + w + d <= f) {
//			noud[1] = noudo(s + a, w + d);
//
//		}
//		else if (s + b + w + c <= f) {
//			noud[2] = noudo(s + b, w + c);
//
//		}
//		else if (s + b + w + d <= f) {
//			noud[3] = noudo(s + b, w + d);
//		}
//		auto maxe = max_element(noud.begin(), noud.end());
//		if (*maxe != 0) {
//			int maxi = distance(noud.begin(), maxe);
//			switch (maxi) {
//			case 0:
//				s += a;
//				w += c;
//				break;
//			case 1:
//				s += a;
//				w += d;
//				break;
//			case 2:
//				s += b;
//				w += c;
//				break;
//			case 3:
//				s += b;
//				w += d;
//			}
//		}
//		else break;
//
//	}
//	cout << s << w;
//	return 0;
//}
//
//
//
