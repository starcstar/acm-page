#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n, m, a[100005];
int work(int x)
{
	int sum = 0, s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s >= x)
		{
			sum++;
			s = 0;
		}
		s += a[i];
	}
	if (s >= x)
		++sum;
	return sum;
}
signed main()
{
	scanf("%lld%lld", &n, &m);
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), r += a[i];
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (work(mid) >= m)
			l = mid;
		else
			r = mid - 1;
	}
	printf("%lld", l);
}