#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
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
#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
#define DBG(str) //cerr<<(str)<<endl;
struct interval {
	int index, l, r;
};
//bool lt_left(interval a, interval b) {
//	return a.l < b.l;
//}
//bool gt_right(interval a, interval b) {
//	return a.r > b.r;
//}
int main() {
	int n;
	cin >> n;
	vector<interval>I(n);
	auto lt_left = [](interval a, interval b) {return a.l < b.l; };
	auto gt_right = [](interval a, interval b) {return a.r > b.r; };
	priority_queue<interval, vector<interval>, decltype(lt_left)>leftq(lt_left);
	priority_queue<interval, vector<interval>, decltype(gt_right)>rightq(gt_right);
	rep(i, 0, n) {
		cin >> I[i].l >> I[i].r;
		I[i].index = i;

		leftq.push(I[i]);
		rightq.push(I[i]);
	}
	//rep(i, 0, n) {
	//	//cerr << leftq.top().l << endl;
	//	leftq.pop();
	//}
	////cerr << endl;
	//rep(i, 0, n) {
	//	//cerr << rightq.top().r << endl;
	//	rightq.pop();

	//}

	auto simu = [&](bool rlrl, priority_queue<interval, vector<interval>, decltype(lt_left)>leftq, priority_queue<interval, vector<interval>, decltype(gt_right)>rightq) {
		vector<bool>deleted(n, false);
		ll K = 0;
		int delcnt = 0;
		int pos = 0;
		int i = 0;
		while (delcnt < n) {
			int newpos = 0;
			interval next;
			if (i % 2 == rlrl) {
				next = leftq.top();
				leftq.pop();
				newpos = next.l;
			}
			else {
				next = rightq.top();
				rightq.pop();
				newpos = next.r;
			}
			if (deleted[next.index])continue;
			delcnt++;
			deleted[next.index] = true;
			i++;
			if (next.l <= pos && pos <= next.r)continue;
			K += abs(newpos - pos);
			pos = newpos;
			//cerr << "delcnt:" << delcnt << ", K:" << K << endl;
			//cerr << "selected:(index,l,r)=" << next.index << "," << next.l << "," << next.r<<endl;

		}
		K += abs(pos);
		//cerr << "res of " << rlrl << ": " << K << endl;
		return K;
	};
	ll ans1 = simu(0, leftq, rightq);
	ll ans2 = simu(1, leftq, rightq);
	cout << max(ans1, ans2);




	return 0;
}



