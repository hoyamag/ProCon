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
//
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//
//vector<vector<int>> warshallFloyd(int n, vector<int>a, vector<int>b, vector<int>c) {
//	// n : グラフのノードの数
//	const int C_LIMIT = 100001;
//	int m = c.size();
//	vector<vector<int>> d = vector<vector<int>>(n, vector<int>(n, C_LIMIT));
//	for (int i = 0; i < n; i++) d[i][i] = 0;
//	for (int i = 0; i < m; i++) {
//		d[a[i] - 1][b[i] - 1] = d[b[i] - 1][a[i] - 1] = c[i];
//	}
//	for (int k = 0; k < n; k++) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//			}
//		}
//	}
//	/*cout << endl;
//	for (int i = 0; i < n; i++) {
//	for (int j = 0; j < n; j++) {
//	cout << d[i][j] << " ";
//	}
//	cout << endl;
//	}*/
//	return d;
//
//}
//
//int dfs(int pa, vector<int>r, vector<vector<int>>d) {
//	/*cout << "dfs:" << pa + 1 << ", ";
//	rup(i, 0, r.size()) cout << r[i] << " ";
//	cout << endl;*/
//	vector<int> sum = vector<int>(r.size(), 0);
//
//	if (r.size() == 1) {
//		return d[pa][r[0] - 1];
//	}
//	else {
//		for (int i = 0; i < r.size(); i++) {
//
//			vector<int> rsub(r.begin(), r.begin() + i);
//			rsub.insert(rsub.end(), r.begin() + i + 1, r.end());
//			int cur = r[i] - 1;
//			sum[i] = d[pa][cur] + dfs(cur, rsub, d);
//		}
//	}
//	//cout << "dfsres:" << sum[*min_element(sum.begin(), sum.end())]<<", "<<pa+1<<" to ";
//	//rup(i, 0, r.size()) cout << r[i] << " ";
//	//cout << endl;
//
//	return *min_element(sum.begin(), sum.end());
//
//
//}
//
//
//int main() {
//	//vector<int> p = { 1,2,3 ,4,5 };
//	//vector<int> psub(p.begin(), p.begin() + 2);
//	//psub.insert(psub.end(), p.begin() + 3, p.end());
//	//p[0] = -10;
//	//cout << *min_element(p.begin(), p.end());
//
//
//	int N, M, R;
//	cin >> N >> M >> R;
//	vector<int>r = vector<int>(R, 0);
//	vector<int>a = vector<int>(M, 0);
//	vector<int>b = vector<int>(M, 0);
//	vector<int>c = vector<int>(M, 0);
//	rup(i, 0, R) cin >> r[i];
//	rup(i, 0, M) cin >> a[i] >> b[i] >> c[i];
//	vector<vector<int>> d = warshallFloyd(N, a, b, c);
//	vector<int> sum = vector<int>(r.size(), 0);
//	rup(i, 0, r.size()) {
//		/*vector<int> rsub(r.begin(), r.begin() + i);
//		rsub.insert(rsub.end(), r.begin() + i + 1, r.end());
//		*/
//		vector<int> rsub(r);
//		rsub.erase(rsub.begin() + i);
//		int cur = r[i] - 1;
//		sum[i] = dfs(cur, rsub, d);
//
//	}
//	cout << *min_element(sum.begin(), sum.end());
//
//
//	return 0;
//}
//
//
//
