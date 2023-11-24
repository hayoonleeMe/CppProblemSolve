#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100004];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int n;
		cin >> n;
		if (i > 1)
			arr[i] = n + arr[i - 1];
		else
			arr[i] = n;
	}

	while (M--)
	{
		int i, j;
		cin >> i >> j;

		if (i == 1)
			cout << arr[j] << '\n';
		else
			cout << arr[j] - arr[i - 1] << '\n';
	}
}