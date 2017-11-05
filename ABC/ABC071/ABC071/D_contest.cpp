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
//#define ul  unsigned long long
//
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//ul M = 1000000007;
//class domino {
//	//int index;
//	
//	
//
//public:
//	int youngerTouching;
//	domino(int youngerTouching) {
//		//this->index = index;
//		this->youngerTouching = youngerTouching;
//	}
//	domino() {
//		this->youngerTouching = 0;
//	}
//};
//int main() {
//	int n;
//	string s[2];
//	cin >> n;
//	cin >> s[0];
//	cin >> s[1];
//	vector<domino> d = vector<domino>(n);
//	int dominoIndex = 0;
//
//	for (int col = 0; col < n-1; col++) {
//		for (int row = 0; row < 2; row++) {
//			if (row == 0) {
//				if (s[row][col] == s[row][col + 1]) {
//					// **
//					//
//					if (col - 1 >= 0) {
//						d[dominoIndex] = domino(1);
//						dominoIndex++;
//					}
//					else {
//						d[dominoIndex] = domino(0);
//						dominoIndex++;
//					}
//				}
//				else if (s[row][col] == s[row + 1][col]) {
//					// *
//					// *
//					if (col - 1 >= 0) {
//						if (s[row][col - 1] == s[row + 1][col - 1]) {
//							d[dominoIndex] = domino(1);
//							dominoIndex++;
//						}
//						else {
//							d[dominoIndex] = domino(2);
//							dominoIndex++;
//						}
//					}
//					else {
//						d[dominoIndex] = domino(0);
//						dominoIndex++;
//					}
//				}
//			}
//			else {
//				if (s[row][col] == s[row][col + 1]) {
//					//
//					// **
//					d[dominoIndex] = (col - 1 >= 0) ? domino(2):domino(1);
//					dominoIndex++;
//
//				}
//			}
//		}
//	}
//	
//	if (s[0][n - 1] == s[1][n - 1]) {
//		if (n - 2 >= 0) {
//			if (s[0][n - 2] == s[1][n - 2]) {
//				d[dominoIndex] = domino(1);
//			}
//			else {
//				d[dominoIndex] = domino(2);
//			}
//		}
//		else {
//			d[dominoIndex] = domino(0);
//		}
//		dominoIndex++;
//	}
//	ul ans = 1;
//	for (int i = 0; i < d.size(); i++) {
//		ans *= ((ul)3 - (ul)d[i].youngerTouching);
//		ans %= M;
//	}
//	cout << ans << endl;;
//
//	return 0;
//}
//
//
//
