﻿#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int arr[9], sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);

	int i, j;
	for (i = 0; i < 9; ++i)
	{
		for (j = i + 1; j < 9; ++j)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				for (int k = 0; k < 9; ++k)
					if (k != i && k != j)
						cout << arr[k] << '\n';
				return 0;
			}
		}
	}
}