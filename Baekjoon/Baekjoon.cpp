#include <bits/stdc++.h>
using namespace std;

int N;
int a[100'002];
int d[100'002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	d[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		for (int j = d[i-1]; j >= 0; --j)
			if (j + 1 <= a[i])
			{
				d[i] = j + 1;
				break;
			}
	}

	cout << *max_element(d, d + N + 1);
}

//13
//3 1 4 1 5 9 2 6 5 3 5 8 9
//d[i] : i번째 열이 포함될 때 최대 계단 길이
//
//d[1] = 1
//d[2] = 1
//d[3] = 2
//d[4] = 1
//d[5] = 2
//d[6] = 3
//d[7] = 2
//d[8] = 3
//d[9] = 4
//d[10] = 3
//d[11] = 4
//d[12] = 5
//d[13] = 6