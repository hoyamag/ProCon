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
//ul M = 1000000007;
//class domino {
//	//int index;
//	int youngerTouching;
//
//public:
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
//	for (int col = 0; col < n - 1; col++) {
//		for (int row = 0; row < 2; row++) {
//			if (row == 0) {
//				if (s[col][row] == s[col + 1][row]) {
//					// **
//					//
//					if (col - 1 >= 0) {
//						d[dominoIndex] = domino(1);
//					}
//					else {
//						d[dominoIndex] = domino(0);
//					}
//				}
//				else if (s[col][row] == s[col][row + 1]) {
//					// *
//					// *
//					if (col - 1 >= 0) {
//						if (s[col - 1][row] == s[col - 1][row + 1]) {
//							d[dominoIndex] = domino(1);
//						}
//						else {
//							d[dominoIndex] = domino(2);
//						}
//					}
//					else {
//						d[dominoIndex] = domino(0);
//					}
//				}
//				dominoIndex++;
//			}
//			else {
//				if (s[col][row] == s[col + 1][row]) {
//					//
//					// **
//					d[dominoIndex] = (col - 1 >= 0) ? domino(2) : domino(1);
//					dominoIndex++;
//
//				}
//			}
//		}
//	}
//	if (s[n - 1][0] == s[n - 1][1]) {
//		if (s[n - 2][0] == s[n - 2][1]) {
//			d[dominoIndex] = domino(1);
//		}
//		else {
//			d[dominoIndex] = domino(2);
//		}
//		dominoIndex++;
//	}
//
//	return 0;
//}
//
//
//
