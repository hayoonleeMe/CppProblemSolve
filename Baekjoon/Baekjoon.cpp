#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000000;
int N;
int d[105][10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int k = 1; k <= 9; ++k)
		d[1][k] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int k = 0; k <= 9; ++k)
		{
			if (k != 0)
				d[i][k] += d[i - 1][k - 1];
			if (k != 9)
				d[i][k] += d[i - 1][k + 1];
			d[i][k] %= mod;
		}
	}

	int ans = 0;
	for (int k = 0; k <= 9; ++k)
	{
		ans += d[N][k];
		ans %= mod;
	}

	cout << ans;
}