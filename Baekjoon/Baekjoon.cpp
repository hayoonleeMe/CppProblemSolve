﻿#include <bits/stdc++.h>
using namespace std;

int N;
int a[1'000'002];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	a[0] = a[N];
	for (int i = 0; i < N; ++i)
	{
		if (a[i] >= a[i + 1])
			++ans;
	}

	cout << ans;
}