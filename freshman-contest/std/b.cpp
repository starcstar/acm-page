#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dwn(i, a, b) for (int i = a; i >= b; i--)
#define lowbit(x) (x & (-x))
#define MAXN 1002501
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

struct node
{
	int k, l, id;
} q[MAXN], p[MAXN];

bool cmpp(node x, node y)
{
	return x.k > y.k;
}

int n, a[MAXN], m, c[MAXN], inf, ans[MAXN];

void ins(int x, int y)
{
	while (x <= n)
		c[x] = min(c[x], y), x += lowbit(x);
}

int qry(int x)
{
	int res = n + 1;
	while (x)
		res = min(res, c[x]), x -= lowbit(x);
	return res;
}

int rev(int x)
{
	return n - x + 1;
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, n) c[i] = n + 1;
	rep(i, 1, n) a[i] = read(), q[i] = {a[i], i, i};
	int cnt = 1;
	rep(i, 1, m)
	{
		p[i].k = read();
		p[i].l = read();
		p[i].id = i;
	}
	sort(q + 1, q + n + 1, cmpp);
	sort(p + 1, p + m + 1, cmpp);
	rep(i, 1, m)
	{
		while (cnt <= n && q[cnt].k >= p[i].k)
		{
			ins(rev(q[cnt].l), q[cnt].l);
			++cnt;
		}
		//		cout<<"I:"<<p[i].l<<" "<<qry(rev(p[i].l))<<endl;
		ans[p[i].id] = qry(rev(p[i].l)) - p[i].l;
	}
	rep(i, 1, m) if (!ans[i]) puts("all in acm");
	else printf("%d\n", ans[i]);
	return 0;
}