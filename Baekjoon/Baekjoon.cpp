﻿#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long A, B;
	cin >> A >> B;

	if (A > B)
		swap(A, B);
	else if (A == B)
	{
		cout << 0;
		return 0;
	}
	
	cout << B - A - 1 << '\n';

	for (long long i = A + 1; i < B; ++i)
		cout << i << ' ';
}