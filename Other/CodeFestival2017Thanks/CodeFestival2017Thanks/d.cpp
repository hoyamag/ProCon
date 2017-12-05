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
#define all(t) t.begin(), t.end()


int main() {
	ull n, m;
	cin >> n >> m;
	ull ma = 0;
	//rep(i, m) {
	//	ma = max(ma, ((i + 1)*n) % m%m);
	//}
	if(n>m)	ma = (n%m)*(m - 1);
	else ma = m-n;
	cout << ma << endl;
	return 0;
}



