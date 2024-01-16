﻿#include <bits/stdc++.h>
using namespace std;

int N;
int a[1002];
int asc[1002];
int dsc[1002];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	for (int i = 1; i <= N; ++i)
	{
		asc[i] = 1;
		for (int j = 1; j < i; ++j)
			if (a[i] > a[j])
				asc[i] = max(asc[i], asc[j] + 1);
	}

	for (int i = N; i >= 1; --i)
	{
		dsc[i] = 1;
		for (int j = N; j > i; --j)
			if (a[i] > a[j])
				dsc[i] = max(dsc[i], dsc[j] + 1);
	}

	for (int i = 1; i <= N; ++i)
		ans = max(ans, asc[i] + dsc[i] - 1);
	cout << ans;
}

//10
//1 5 2 1 4 3 4 5 2 1
//
//asc[i] : 1~i번째까지에서 가장 긴 증가 부분수열 길이
//dsc[i] : N~i번째까지에서 가장 긴 감소 부분수열 길이
//
//asc[i] + dsc[i] - 1(중복)