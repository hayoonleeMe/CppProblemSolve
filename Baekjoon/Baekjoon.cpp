#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[11];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	int count = 0;
	for (int i = N; i > 0; --i)
	{
		if (K / arr[i] == 0)
			continue;

		count += K / arr[i];
		K = K % arr[i];
	}

	cout << count;
}