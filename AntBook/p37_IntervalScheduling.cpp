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
#include<utility>
#include<tuple>
using namespace std;
#define ull unsigned long long
#define llong long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()

int IntervalScheduling(int n, vector<long>s, vector<long>t) {
	// n : number of existing work
	// s : start time of each work
	// t : end time of each work
	//return : how many work you can accomplish
	// my solution
	int sum = 0;
	int now = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		long mint = 1e10;
		int nextTime=now;
		rep(i, n) {
			if (now < s[i] && t[i] < mint) {
				nextTime = t[i];
				mint = t[i];
				flag = true;
				sum++;
			}
		}
		now = nextTime;
	}
	return sum;
}
int IntervalScheduling2(int n, vector<long>s, vector<long>t) {
	// n : number of existing work
	// s : start time of each work
	// t : end time of each work
	// return : how many work you can accomplish
	// by book, use pair<> and sort to make fast and simple.
	vector<pair<int, int>> work(n);
	rep(i, n)work[i] = make_pair(t[i], s[i]);
	sort(all(work));
	long now = 0;
	int sum = 0;
	rep(i, n) {
		if (now < work[i].second) {
			now = work[i].first;
			sum++;
		}
	}
	return sum;
}


int main() {
	cout << IntervalScheduling(5, { 1,2,4,6,8 }, { 3,5,7,9,10 }) << endl;
	cout << IntervalScheduling2(5, { 1,2,4,6,8 }, { 3,5,7,9,10 }) << endl;
	return 0;
}

