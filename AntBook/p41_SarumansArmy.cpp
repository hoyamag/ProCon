#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
//#include<initializer_list>
#include<map>
#include<set>
//#include<utility>
//#include<tuple>
using namespace std;
#define ull unsigned long long
#define llong long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
int SarumansArray(vector<int>x, int r) {
	// don't work
	int n = x.size();
	sort(all(x));
	int prei = -1;
	int prev = -r;
	int ans = 0;
	int nowi = 0;
	while (nowi < n) {
		int j = distance(x.begin(), upper_bound(x.begin() + nowi, x.end(), prev + r));
		if (j == n) break;
		int next = distance(x.begin(), lower_bound(x.begin() + j, x.end(), x[j] + r, greater<int>()));
		nowi = next;
		ans++;
		if (next == n)break;
		prev = x[next];

	}
	return ans;
}
int MaxInR(vector<int> x, int r, int st) {
	int n = x.size();

	for (int i = st; i < n; i++) {
		if (x[i] == x[st] + r)return i;
		else if (x[i] > x[st] + r)return i - 1;
	}
	return n;
}
int SarumansArray2(vector<int>x, int r) {
	int n = x.size();
	sort(all(x));
	int st = 0;
	int mark = MaxInR(x, r, st);
	int ans = 1;
	while (mark < n) {
		st = n;
		for (int j = mark + 1; j < n; j++) {
			if (x[j] > x[mark] + r) {
				st = j;
				break;
			}
		}
		if (st == n) break;
		mark = MaxInR(x, r, st);
		ans++;
	}
	return ans;
}
int main() {

	//vector<int> a = { 1,2,3 };
	//cout << distance(a.begin(), lower_bound(all(a), 2)) << endl;
	//cout << distance(a.begin(), upper_bound(all(a), 2)) << endl;
	//a = { 1,1,2,2,3,3 };
	//cout << distance(a.begin(), lower_bound(all(a), 2)) << endl;
	//cout << distance(a.begin(), upper_bound(all(a), 2)) << endl;
	//a = { 1,1,3,3 };
	//cout << distance(a.begin(), lower_bound(all(a), 2)) << endl;
	//cout << distance(a.begin(), upper_bound(all(a), 2)) << endl;
	//cout << endl;

	//a = { 1,2,3 };
	//cout << distance(a.begin(), lower_bound(all(a), 2, greater<int>())) << endl;
	//cout << distance(a.begin(), upper_bound(all(a), 2, greater<int>())) << endl;
	//a = { 1,1,2,2,3,3 };
	//cout << distance(a.begin(), lower_bound(all(a), 2, greater<int>())) << endl;
	//cout << distance(a.begin(), upper_bound(all(a), 2, greater<int>())) << endl;
	//a = { 1,1,3,3 };
	//cout << distance(a.begin(), lower_bound(all(a), 2, greater<int>())) << endl;
	//cout << distance(a.begin(), upper_bound(all(a), 2, greater<int>())) << endl;
	//cout << endl;

	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 0) == 6) << endl;
	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 1) == 2) << endl;
	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 2) == 2) << endl;
	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 3) == 1) << endl;
	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 4) == 1) << endl;
	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 5) == 1) << endl;
	//cout << (SarumansArray2({ 1,2,3,4,5,6 }, 6) == 1) << endl;
	//cout << (SarumansArray2({ 1,7,15,20,30,50 }, 10) == 3) << endl;
	while (1) {
		int r, n;
		cin >> r >> n;
		if (r == -1 && n == -1)break;
		vector<int>x(n, 0);
		rep(i, n)cin >> x[i];
		cout << SarumansArray2(x, r) << endl;
	}
	return 0;
}
