#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define repn(i, n) for (int i = 1; i <= n; ++i)

using namespace std;

int n;
string s, t, ans;

int main()
{
    cin >> n >> s;
    ans = s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'p')
        {
            t = s;
            t[i] = 'd';
            ans = min(ans, t);
            t = s;
            for (int j = 0; j < n; j++)
                if (s[j] == 'p')
                {
                    reverse(t.begin() + j, t.begin() + i + 1);
                    for (int k = j; k <= i; ++k)
                        if (t[k] == 'p')
                            t[k] = 'd';
                        else
                            t[k] = 'p';
                    ans = min(ans, t);
                    break;
                }
        }
    }
    cout << ans;
    return 0;
}