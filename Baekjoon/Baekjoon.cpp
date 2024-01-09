﻿#include <bits/stdc++.h>
using namespace std;

int N;
int a[1005];
int d[1005];
const int MAX = 0x7f7f7f7f;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	fill(d, d + N + 1, MAX);
	d[1] = 0;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
			if (j + a[j] >= i)
				d[i] = min(d[i], d[j] + 1);
	}

	if (d[N] == MAX)
		cout << -1;
	else
		cout << d[N];
}

//10
//1 2 0 1 3 2 1 5 4 2
//d[1] = 0
//d[2] = 1 => 1+1
//d[3] = 2
//d[4] = 
//d[i] = min(d[1]+1, d[2]+1, ..., d[i-1]+1) (단, i번째에 도달할 수 있을 때만)