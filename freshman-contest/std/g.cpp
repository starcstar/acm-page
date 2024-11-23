#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dwn(i, a, b) for (int i = a; i >= b; i--)
#define lowbit(x) (x & (-x))
#define MAXN 1002501
#define int long long
#define mp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
		x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return x * f;
}
const int mod = 998244353;
int n, k, ans, a, b;
int ksm(int x, int y)
{
	int res = 1;
	while (y)
	{
		if (y & 1)
			res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
signed main()
{
	n = read();
	k = read();
	rep(i, 1, n)
	{
		a = read();
		b = read();
		ans += a * ksm(b, mod - 2);
		ans %= mod;
	}
	// cout<<ans<<endl;
	ans = ans * k % mod;
	ans = ans * ksm(n, mod - 2) % mod;
	cout << ans;
	return 0;
}