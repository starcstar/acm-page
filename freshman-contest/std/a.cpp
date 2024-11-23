#include <bits/stdc++.h>

using namespace std;

int n, m, x, flag = 0;

bool a[1005];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		string s;
		cin >> s >> x;
		if (x < 1 || x > n)
		{
			flag = 1;
			continue;
		}
		if (s == "alloc")
		{
			if (a[x] == 0)
				a[x] = 1;
			else
				flag = 1;
		}
		else if (s == "free")
		{
			if (a[x] == 1)
				a[x] = 0;
			else
				flag = 1;
		}
	}
	if (flag == 1)
		cout << "Illegal operation";
	else
		cout << "All operations are safe";
	return 0;
}