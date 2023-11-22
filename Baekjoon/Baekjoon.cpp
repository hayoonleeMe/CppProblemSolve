﻿#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int seq[10];

void func(int k, int st)
{
	if (k == M)
	{
		for (int i = 0; i < M; ++i)
			cout << seq[i] << ' ';
		cout << '\n';
		return;
	}

	int prev = 0;
	for (int i = st; i < N; ++i)
	{
		if (arr[i] != prev)
		{
			seq[k] = arr[i];
			func(k + 1, i);
			prev = arr[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	func(0, 0);
}