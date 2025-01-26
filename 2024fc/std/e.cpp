#include <iostream>

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);

    int T;
    std::cin >> T;
    while (T--)
    {
        int n, k;
        std::cin >> n >> k;
        std::cout << (k == 1 ? "YES\n" : "NO\n");
    }
}