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
#include<iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>t(n + 2, 0);
	t[0] = t[n + 1] = 0;
	for (int i = 1; i < n + 1; i++) cin >> t[i];
	vector<int>v(n + 2, 0);
	v[0] = v[n + 1] = 0;
	for (int i = 1; i < n + 1; i++)cin >> v[i];
	int totalTime = 0;
	for (int i = 0; i < n + 2; i++)totalTime += t[i];
	vector<double>maxv(2 * totalTime + 1, 0);
	int timeSum = 0;
	for (int i = 1; i < t.size()-1; i++) {
		maxv[timeSum] = min(v[i], v[i - 1]);
		for (int j = timeSum + 1; j < timeSum + 2 * t[i]; j++) {
			maxv[j] = v[i];
		}
		timeSum += 2 * t[i];
	}
	maxv[0] = maxv[2*totalTime] = 0;

	for (int i = 1; i < maxv.size(); i++) {
		maxv[i] = min(maxv[i], maxv[i - 1] + 0.5);
	}
	for (int i = maxv.size() - 2; i >= 0; i--) {
		maxv[i] = min(maxv[i], maxv[i + 1] + 0.5);
	}
	double distance = 0;
	for (int i = 0; i < maxv.size() - 1; i++) {
		distance += 0.5*0.5*(maxv[i + 1] + maxv[i]);
	}
	cout << std::fixed<<setprecision(4)<<distance << endl;
	//printf("%.10f\n", distance);
	return 0;
}

