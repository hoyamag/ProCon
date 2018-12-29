#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail>
void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
};
struct edge {
	int to, cap, rev;
};
const int MAX_V = 300;
const int INF = INT32_MAX;
vector<bool>used(MAX_V);
vector<edge>G[MAX_V];
void add_edge(int from, int to, int cap) {
	G[from].push_back(edge({ to, cap, (int)G[to].size() }));
	G[to].push_back(edge({ from, 0, (int)G[from].size() - 1 }));

}
int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}


	return 0;
}
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		REP(i, 0,MAX_V)used[i] = 0;
		int f = dfs(s, t, INF);
		if (f == 0)return flow;
		flow += f;
	}
}







int main() {

	int n;
	cin >> n;
	vector<int>a(n), b(n), c(n), d(n);
	rep(i, n)cin >> a[i] >> b[i];
	rep(i, n)cin >> c[i] >> d[i];
	int s = 2*n ;
	int t = 2*n + 1;
	rep(i, n) {
		add_edge(s, i, 1);
		add_edge(n + i, t, 1);
	}
		
	rep(i, n) {
		rep(j, n) {
			if (a[i] < c[j] && b[i] < d[j]) {
				add_edge(i, j+n, 1);
			}
		}
	}
	cout << max_flow(s, t);
	

	return 0;
}



;
string s;
VEC<LL> a;
string h = "hard";
LL f(int start) {
  REP(i,start,n){

  }



}

int main() {
  int n;
  cin >> n;
  a = VEC<LL>(n);
  cin >> s;
  REP(i, 0, n) { cin >> a[i]; }

  return 0;
}
