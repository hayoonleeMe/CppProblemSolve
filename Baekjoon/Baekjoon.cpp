﻿#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100005], d[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
	}

	while (M--)
	{
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';
	}
}