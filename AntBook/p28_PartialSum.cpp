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

bool PartialSum(vector<int>a, int value) {
	// aの要素をいくつか選び、その和をちょうどvalueにできるかどうかを出力する
	if (a.size() == 0) {
		if (value==0) return true;
		else return false;
	}
	vector<int>sub(a.begin() + 1, a.end());
	int newValue = value - a[0];
	if (PartialSum(sub, newValue)) return true;
	else if (PartialSum(sub, value)) return true;
	else return false;
}

int main() {

	cout << PartialSum({ 1,2,3 }, 1) << endl;
	cout << PartialSum({ 1,2,3 }, 2) << endl;
	cout << PartialSum({ 1,2,3 }, 3) << endl;
	cout << PartialSum({ 1,2,3 }, 4) << endl;
	cout << PartialSum({ 1,2,3 }, 5) << endl;
	cout << PartialSum({ 1,2,3 }, 6) << endl;
	cout << PartialSum({ 1,2,4,7 }, 15) << endl;
	return 0;
}



