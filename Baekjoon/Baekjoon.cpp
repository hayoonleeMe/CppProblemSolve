#include <bits/stdc++.h>
using namespace std;

int N;
int a[1002];
int d[1002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
		d[i] = a[i];
	}

	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= i / 2; ++j)
			d[i] = min(d[i], d[j] + d[i - j]);

	cout << d[N];
}

//10
//1 1 2 3 5 8 13 21 34 55
//
//d[i] : i개 갖기 위해 지불해야 하는 금액 최소
//d[1] = 1
//d[2] = min(a[2], d[1]+d[1]) = 1
//d[3] = min(a[3], d[2]+d[1]) = 2
//d[4] = min(a[4], d[1]+d[3], d[2]+d[2]) = 2
//d[i] = min(a[i], d[1]+d[i-1], d[2]+d[i-2], d[i/2][i-i/2])