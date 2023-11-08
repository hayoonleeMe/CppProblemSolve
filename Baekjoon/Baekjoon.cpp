#include <bits/stdc++.h>
using namespace std;

int N;
int arr[20];

int Func(int interval, int cost)
{
	int ret = 0;
	for (int i = 0; i < N; ++i)
	{
		int c = (arr[i] / interval + 1) * cost;
		ret += c;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int Y = Func(30, 10);
	int M = Func(60, 15);

	if (Y < M)
		cout << "Y " << Y;
	else if (M < Y)
		cout << "M " << M;
	else
		cout << "Y M " << Y;
}