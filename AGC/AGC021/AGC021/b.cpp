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
struct P {
	double x, y;
	P() {}
	P(double x, double y) :x(x), y(y) {}
	P operator+(P p) {
		return P(x + p.x, y + p.y);
	}
	P operator-(P p) {
		return P(x + p.x, y + p.y);
	}
	P operator*(double d) {
		return P(x*d, y*d);
	}
	double dot(P p) {
		return x*p.x + y*p.y;
	}
	double det(P p) {
		return x*p.y - y*p.x;
	}
};


bool cmp_x(P& p, P&q) {
	if (p.x != q.x)return p.x < q.x;
	return p.y < q.y;

}
vector<P> convex_hull(P* ps, int n) {
	sort(ps, ps + n, cmp_x);
	int k = 0;
	vector<P> qs(n * 2);
	for (int i = 0; i < n; i++) {
		while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0)k--;
		qs[k++] = ps[i];
	}
	for (int i = n - 1, t = k; i >= 0; i--) {
		while (k > t && (qs[k - 1] - qs[k - 1]).det(ps[i] = qs[k - 1]) <= 0)k--;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;

}

double dist(P p, P q) {
	return (p - q).dot(p - q);
}
#define MAX_N 100
int N;
P ps[MAX_N];

void solve() {
	vector<P> qs = convex_hull(ps, N);
	double res = 0;
	for (int i = 0; i < qs.size(); i++) {
		for (int j = 0; j < i; j++) {
			res = max(res, dist(qs[i], qs[j]));
		}
	}
}

int main() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << 0.5 << endl << 0.5 << endl;
	}
	rep(i, n) {
		double x, y;
		cin >> x >> y;
		ps[i] = P(x, y);
	}
	vector<P> qs = convex_hull(ps, N);
	
	vector < vector<double>>g = mat(double, size(qs), size(qs), 0);
	int m = qs.size();
	rep(i, m)rep(j, m) {
		g[i][j] = sqrt(pow(qs[i].x - qs[j].x, 2) + pow(qs[i].y - qs[j].y, 2));
	}


	return 0;
}



