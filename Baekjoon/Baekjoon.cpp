#include <bits/stdc++.h>
using namespace std;

int N;
int d[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int p = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (i >= (p + 1) * (p + 1))
		{
			++p;
			d[p * p] = 1;
			continue;
		}

		int m = 0x7f7f7f7f;
		for (int j = p; j > 0; --j)
			m = min(m, (i / (j * j)) * d[j * j] + d[(i % (j * j))]);
		if (m != 0x7f7f7f7f)
			d[i] = m;
	}

	cout << d[N];
}