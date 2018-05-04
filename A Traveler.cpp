//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0549
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
//èhèÍí¨ÇÕnå¬Å@mì˙ä‘
int n, m, pos = 0, a;
long long ans = 0;
long long t[100000];
int main()
{
	cin >> n >> m;
	t[0] = 0;
	//ó›êœòa
	for (int i = 1; i < n; i++)
	{
		cin >> t[i];
		t[i] += t[i - 1];
	}
	pos = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		ans += abs(t[pos] - t[pos + a]);
		ans %= 100000;
		pos += a;
	}
	cout << ans << endl;
	return 0;
}