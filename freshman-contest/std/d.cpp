#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    long long s = 0;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x, s += x;
    }
    for (int i = 1; i <= N; i++)
        cout << s / N + ((N - i) < s % N) << " ";
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}