#include <bits/stdc++.h>
using namespace std;

int K, N;
int a[10'002];

bool Solve(long long x)
{
	long long num = 0;
	for (int i = 0; i < K; ++i)
		num += a[i] / x;
	return num >= N;
}

// parametric search
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; ++i)
		cin >> a[i];

	long long st = 1;
	long long en = 0x7fffffff;

	while (st < en)
	{
		// st와 en이 1차이 날 때, 무한루프에 빠짐
		// st=1, en=2, mid = 1, Solve(mid) = true => st =1 => 무한루프
		//long long mid = (st + en) / 2;
		long long mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}