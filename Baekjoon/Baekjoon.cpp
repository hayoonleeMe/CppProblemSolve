#include <bits/stdc++.h>
using namespace std;

int K;
int arr[15];
int seq[15];

void func(int k, int st)
{
	if (k == 6)
	{
		for (int i = 0; i < 6; ++i)
			cout << seq[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < K; ++i)
	{
		seq[k] = arr[i];
		func(k + 1, i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (cin >> K; K != 0; cin >> K)
	{
		for (int i = 0; i < K; ++i)
			cin >> arr[i];

		func(0, 0);
		cout << '\n';
	}
}