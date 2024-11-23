#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;
using int2 = array<int, 2>;

#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), ind(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i], ind[p[i]] = i;

    int cnt = 0;
    vector<int2> opt;
    for (int x = 1; x <= n; x++)
        if (p[x] != x)
        {
            int y = ind[x];
            opt.push_back({x, y});
            ++cnt;
            swap(ind[x], ind[p[x]]);
            swap(p[x], p[y]);
        }

    cout << cnt << '\n';
    for (auto [x, y] : opt)
        cout << x << ' ' << y << '\n';
}
// 1 2 3 4 5 6 7 9 8 10

int main()
{
    ios::sync_with_stdio(0),
        cin.tie(0), cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}