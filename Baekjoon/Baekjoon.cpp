#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int sum = 0;
	int minV = 100;

	for (int i = 0; i < 7; ++i)
	{
		int t;
		cin >> t;
		if (t % 2 == 1)
		{
			sum += t;

			if (t < minV)
				minV = t;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << minV;
}