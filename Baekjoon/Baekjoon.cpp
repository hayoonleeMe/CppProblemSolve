#include <bits/stdc++.h>
using namespace std;

#define R 0
#define G 1
#define B 2
int N;
int r[1005];
int g[1005];
int b[1005];
int d[1005][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int rc, gc, bc;
		cin >> rc >> gc >> bc;
		r[i] = rc;	g[i] = gc;	b[i] = bc;
	}

	d[1][R] = r[1];
	d[1][G] = g[1];
	d[1][B] = b[1];

	for (int i = 2; i <= N; ++i)
	{
		d[i][R] = r[i] + min(d[i - 1][G], d[i - 1][B]);
		d[i][G] = g[i] + min(d[i - 1][R], d[i - 1][B]);
		d[i][B] = b[i] + min(d[i - 1][R], d[i - 1][G]);
	}

	int ans = min({ d[N][R], d[N][G], d[N][B] });
	cout << ans;
}