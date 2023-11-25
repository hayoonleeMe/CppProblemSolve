#include <bits/stdc++.h>
using namespace std;

int N;
int s[305];
int d[305];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	int tot = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> s[i];
		tot += s[i];
	}


	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];

	for (int i = 4; i < N; ++i)
		d[i] = s[i] + min(d[i - 2], d[i - 3]);

	int ans = tot - min(d[N - 1], d[N - 2]);
	cout << ans;
}