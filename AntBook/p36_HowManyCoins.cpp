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

int coinNum(vector<int> myCoins, int pay) {
	// myCoins : how many coin you have
	// pay : how much you should pay
	// return : how many coins you will pay at least
	vector<int>v = { 1,5,10,50,100,500 };
	int n = myCoins.size();
	int sum = 0;
	for (int i = myCoins.size() - 1; i >= 0; i--) {
		int b = min(pay / v[i], myCoins[i]);
		sum += b;
		pay -= v[i] * b;
	}
	return sum;

}

int main() {
	vector<int>c(6, 0);
	rep(i, c.size()) cin >> c[i];
	int a;
	cin >> a;
	int sum = coinNum(c, a);
	std::cout << sum << endl;
	return 0;
}



