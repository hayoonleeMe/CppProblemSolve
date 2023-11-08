#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int arr[21];

	for (int i = 1; i <= 20; ++i)
		arr[i] = i;

	for (int i = 0; i < 10; ++i)
	{
		int a, b;
		cin >> a >> b;

		int c = (b - a + 1) / 2;
		for (int j = 0; j < c; ++j)
			swap(arr[a + j], arr[b - j]);
	}

	for (int i = 1; i <= 20; ++i)
		cout << arr[i] << ' ';
}