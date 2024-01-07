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
		d[i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{ 
		for (int j = 1; j < i; ++j)
			if (a[i] < a[j])
				d[i] = max(d[i], d[j] + 1);
	}

	cout << *max_element(d + 1, d + N + 1);
}

//10 30 10 20 20 10
//d[i] : i번째 수를포함하는 가장 긴 감소하는 부분 수열의 길이
//d[1] = 1 => 10
//d[2] = 1 => 30
//d[3] = 2 => 30 10
//d[4] = 2 => 30 20
//d[5] = 2 => 30 20
//d[6] = 3 => 30 20 10 => max(1, d[5] + 1, d[4] + 1, d[2] + 1)