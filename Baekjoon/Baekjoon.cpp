#include <bits/stdc++.h>
using namespace std;

int T, N, ans;

void func(int k, int tot)
{
	if (k > N)
		return;

	if (tot == N)
	{
		++ans;
		return;
	}

	for (int i : {1, 2, 3})
	{
		func(k + 1, tot + i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;
		ans = 0;

		func(0, 0);

		cout << ans << '\n';
	}
}