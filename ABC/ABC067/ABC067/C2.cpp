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
////	// a[begin]‚©‚ça[floor(end/2)]‚Ì‘˜a‚Æa[floor(end/2)]‚©‚ça[end]‚Ü‚Å‚Ì‘˜a‚Ì·‚ð•Ô‚·B
////	// a[begin]‚©‚ça[end]‚ð2•ªŠ„‚µ‚½‚Æ‚«A
////	//	‚»‚ê‚¼‚ê‚Ì‘˜a‚ªÅ¬‚Æ‚È‚é“Y‚¦Žš
////	//	‚»‚ê‚¼‚ê‚Ì‘˜a
////	//	‚ð•Ô‚·B
////}
////lol bin2(lol begin, lol ned){
//////a‚Ì“Y‚¦Žšbegin‚Æend‚ð—^‚¦‚é‚ÆAbegin~floor(end/2)‚Ì‘˜a‚Æfloor(end / 2 + 1)~end‚Ì‘˜a‚ð”äŠr‚µ‚ÄA
//////begin‚©‚ç‚Ì‚Ù‚¤‚ª‘å‚«‚¯‚ê‚Îbegin‚ðAfloor(end / 2 + 1)‚©‚ç‚Ì•û‚ª‘å‚«‚¯‚ê‚Îfloor(end / 2 + 1)‚ð•Ô‚·
////}
////lol binSearch(lol begin, lol end, leftSum, rightSum) {
////	//a‚Ì“Y‚¦Žšbegin‚Æend‚ð—^‚¦‚é‚ÆAa‚ð2•ªŠ„‚µ‚½‚Æ‚«‚»‚ê‚¼‚ê‚Ì‘˜a‚ªÅ‚à¬‚³‚­‚È‚é‚æ‚¤‚È“Y‚¦Žš‚ð•Ô‚·B
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
////	//vector a‚ð2•ªŠ„‚µ‚½‚Æ‚«A‚»‚ê‚¼‚ê‚Ì‘˜a‚ªÅ‚à‹ß‚­‚È‚é‚æ‚¤‚È“Y‚¦Žš‚ð•Ô‚·B
////	// Ä‹NŠÖ”Bseparate‚É‚Í‚Í‚¶‚ßfloor((a.size())/2)‚ð“n‚·Bx‚Æy‚Ía‚ðseparate‚Å•ª‚¯‚½‚Æ‚«‚ÌA‚»‚ê‚¼‚ê‚Ì•”•ª˜a
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
