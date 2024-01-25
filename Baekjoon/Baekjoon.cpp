#include <bits/stdc++.h>
using namespace std;

int M, N;
int L[1'000'002];

bool Solve(int x)
{
	long long num = 0;
	for (int i = 0; i < N; ++i)
		num += L[i] / x;
	return num >= M;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		cin >> L[i];

	int st = 1;
	int en = 1'000'000'000;

	while (st < en)
	{
		int mid = (st + en + 1) / 2;
		if (Solve(mid))
			st = mid;
		else
			en = mid - 1;
	}

	if (Solve(st))
		cout << st;
	else
		cout << 0;
}