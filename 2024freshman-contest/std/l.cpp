#include <bits/stdc++.h>
using namespace std;
const int N = 410;
int a[N], b[N];
long long f[N][N];
int main()
{
	int T, n, k;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
			scanf("%d", b + i);
		for (int j = 1; j <= k; j++)
		{
			for (int i = 0; i <= n; i++)
				f[j][i] = -1e18;
			for (int L = 1; L <= n; L++)
			{
				for (int R = L; R <= n && R - L + 1 <= j; R++)
				{
					f[j][R] = max(f[j][R], abs(b[R] - a[L]) + f[j - R + L - 1][L - 1]);
				}
			}
			// if(j == k)cerr<<f[j][n]<<endl;
			for (int i = 1; i <= n; i++)
				f[j][i] = max(f[j][i], f[j][i - 1]);
		}
		printf("%lld\n", f[k][n]);
	}
	return 0;
}