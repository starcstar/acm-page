#include <bits/stdc++.h>
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int _{400010};
constexpr int N{100000};
constexpr i64 MY_INF{1ll << 60};
constexpr int mod{998244353};

int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie();

	int _t{1};
	std::cin >> _t;
	while (_t--)
	{
		i64 a, b, a1, b1, a2, b2;
		std::cin >> a >> b >> a1 >> b1 >> a2 >> b2;
		if (a < a1 || b < b1 || a < a2 || b < b2)
		{
			std::cout << "0\n";
			continue;
		}
		i64 tot{(a - a1 + 1) * (b - b1 + 1) % mod * (a - a2 + 1) % mod * (b - b2 + 1) % mod};
		i64 ta{(a - a1 + 1) * (a - a2 + 1) % mod}, tb{(b - b1 + 1) * (b - b2 + 1) % mod};
		if (a >= a1 + a2)
			ta -= ((a - a1 - a2 + 2) * (a - a1 - a2 + 1) % mod),
				ta += mod,
				ta %= mod;
		if (b >= b1 + b2)
			tb -= ((b - b1 - b2 + 2) * (b - b1 - b2 + 1) % mod),
				tb += mod,
				tb %= mod;
		tot -= ta * tb % mod;
		tot += mod;
		tot %= mod;
		std::cout << tot << '\n';
	}
	return 0;
}