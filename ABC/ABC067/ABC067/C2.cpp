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
//#define lol long long
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//
//vector<lol> a;
//
////lol bin(lol begin, lol end) {
////	// a[begin]からa[floor(end/2)]の総和とa[floor(end/2)]からa[end]までの総和の差を返す。
////	// a[begin]からa[end]を2分割したとき、
////	//	それぞれの総和が最小となる添え字
////	//	それぞれの総和
////	//	を返す。
////}
////lol bin2(lol begin, lol ned){
//////aの添え字beginとendを与えると、begin~floor(end/2)の総和とfloor(end / 2 + 1)~endの総和を比較して、
//////beginからのほうが大きければbeginを、floor(end / 2 + 1)からの方が大きければfloor(end / 2 + 1)を返す
////}
////lol binSearch(lol begin, lol end, leftSum, rightSum) {
////	//aの添え字beginとendを与えると、aを2分割したときそれぞれの総和が最も小さくなるような添え字を返す。
////	lol leftSum = sum(begin, floor(end / 2));
////	lol rightSum = sum(floor(end / 2), end);
////	if (leftSum > rightSum) {
////		binSearch(begin, floor(end / 2));
////	}
////	else {
////		binSearch(floor(end / 2), end);
////	}
////}
////lol bin(lol separate, lol x, lol y) {
////	//vector aを2分割したとき、それぞれの総和が最も近くなるような添え字を返す。
////	// 再起関数。separateにははじめfloor((a.size())/2)を渡す。xとyはaをseparateで分けたときの、それぞれの部分和
////	if (x > y) {
////		lol s = floor(separate / 2);
////	}
////
////}
//lol sum(lol begin, lol end) {
//	lol sum = 0;
//	for (lol i = begin; i < end; i++) {
//		sum += a[i];
//	}
//	return sum;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	a = vector<lol>(n, 0);
//	rup(i, 0, n) cin >> a[i];
//	lol s = lol(ceil(n / 2));
//	lol x = sum(0, s);
//	lol y = sum(s, n);
//	lol eva = abs(x-y);
//	if (n != 2) {
//		while (1) {
//
//			lol nx = x;
//			lol ny = y;
//			lol ns = s;
//			if (x > y) {
//				nx -= a[ns - 1];
//				ny += a[ns - 1];
//				ns--;
//			}
//			else {
//				nx += a[ns];
//				ny -= a[ns];
//				ns++;
//			}
//			lol newEva = abs(nx - ny);
//			if (newEva < eva) {
//				x = nx;
//				y = ny;
//				s = ns;
//				eva = newEva;
//			}
//			else {
//				break;
//			}
//		}
//	}
//	cout << eva;
//	return 0;
//}
//
//
//
