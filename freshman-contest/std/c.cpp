#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;
using ll = long long;
using int2 = array<int, 2>;

#define all(x) x.begin(), x.end()

int n;

int ask(int h)
{
    if (h > n)
        return 1;
    cout << "? " << h << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void ans(int h)
{
    cout << "! " << h << endl;
    cout.flush();
}

void solve()
{
    cin >> n;
    // c*(c+1)/2=n
    // c2+c+2(-n)=0
    // dealt=1+8n
    // c=(-1+sqrt(dealt))/2
    // n=7 -> (0 3 5 6 7] -> c=3
    //
    int c = ceil((-1 + sqrtl(1 + ll(n) * 8)) / 2);

    int lst = 0, cur;
    for (int i = c; i > 0; i--)
    {
        cur = lst + i;
        if (ask(cur))
            break;
        lst = cur;
    }
    int res = lst + 1;
    while (not ask(res))
        ++res;
    ans(res - 1);
}

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