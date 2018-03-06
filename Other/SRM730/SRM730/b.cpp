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
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;

double frac(int n) {
	static vector<double> t(51, -1);
	t[0] = 1;
	if (t[n] != -1)return t[n];
	else {
		t[n] = n*frac(n - 1);
		return t[n];
	}

}
double pow2(int n) {
	static vector<double> t(51, -1);
	t[0] = 1;
	if (t[n] != -1) return t[n];
	else {
		t[n] = 2 * pow2(n - 1);
		return t[n];
	}
}
double comb(int n, int r) {
	return frac(n) / (frac(n - r)*frac(r));
}


class ExpectedMinimumPowerDiv2 {
public:

	double findExp(int n, int x) {
		double sum = 0;
		rep1n(i, n - x + 1) {
			sum += pow2(i)*comb(n - i, x - 1);
		}
		return sum / comb(n, x);



	}

};
int main() {
	cout << frac(50)<<endl;
	ExpectedMinimumPowerDiv2 a;
	cout << a.findExp(4, 4) << endl;
	cout << a.findExp(3, 2) << endl;
	cout << a.findExp(3, 1) << endl;
	cout << comb(3, 1) << endl;
	cout << frac(3);
	return 0;
}



