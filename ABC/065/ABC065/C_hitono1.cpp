//#include<cstdio>
//#include<algorithm>
//#define LL long long
//using namespace std;
//const int p = 1000000007;
//int main()
//{
//	int n, m;
//	LL ans = 1;
//	scanf("%d%d", &n, &m);
//	if (n>m) swap(n, m);
//	if (n == m)
//	{
//		for (int i = 1; i <= n; i++) ans = ans*i%p;
//		ans = ans*ans%p;
//		ans = ans * 2 % p;
//	}
//	else if (n == m - 1)
//	{
//		for (int i = 1; i <= n; i++) ans = ans*i%p;
//		ans = ans*ans%p;
//		ans = ans*m%p;
//	}
//	else ans = 0;
//	printf("%lld\n", ans);
//}