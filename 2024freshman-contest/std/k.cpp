#include <bits/stdc++.h>

const int mod = (int)1e9 + 7;

inline int qpow(int x, int k)
{
	int res = 1, buf = x;
	for (; k; k >>= 1)
	{
		if (k & 1)
			res = 1ll * buf * res % mod;
		buf = 1ll * buf * buf % mod;
	}
	return res;
}

int main()
{
	const int N = (int)5e3;
	std::vector<int> fac(N + 1), inv(N + 1);
	fac[0] = 1;
	for (int i = 1; i <= N; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[N] = qpow(fac[N], mod - 2);
	for (int i = N; i; i--)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	auto C = [&](int n, int m)
	{
		if (m > n || m < 0)
			return 0ll;
		return 1ll * fac[n] * inv[n - m] % mod * inv[m] % mod;
	};

	int n, k;
	scanf("%d%d", &n, &k);
	std::vector<int> cnt(n + 2);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int ans = 0;
	std::vector<int> f(n + 2);
	for (int i = 0; i <= cnt[k]; i++)
	{
		int res = 1;
		for (int j = 1; j <= n + 1; j++)
		{
			if (j == k)
				continue;
			f[j] = (f[j] + C(cnt[j], i - (j > k))) % mod;
			res = 1ll * f[j] * res % mod;
		}
		ans = (1ll * res * C(cnt[k], i) + ans) % mod;
	}
	printf("%d\n", ans);
	return 0;
}