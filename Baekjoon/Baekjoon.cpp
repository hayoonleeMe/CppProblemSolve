#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10005];
int d[10005][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	d[1][1] = arr[1];
	d[1][2] = arr[1];

	for (int i = 2; i <= N; ++i)
	{
		d[i][1] = arr[i];
		for (int j = i - 2; j > 0; --j)
			d[i][1] = max({ d[i][1], arr[i] + d[j][1], arr[i] + d[j][2] });
		d[i][2] = arr[i] + d[i - 1][1];
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= 2; ++j)
			ans = max(ans, d[i][j]);
	cout << ans;
}