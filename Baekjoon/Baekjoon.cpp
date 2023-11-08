#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	if (N == 0)
	{
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	::sort(arr.begin(), arr.end());

	float ret = 0.f;
	int limit = int(N * 0.15 + 0.5f);
	for (int i = limit; i < N - limit; ++i)
		ret += arr[i];

	cout << int(ret / (N - 2 * limit) + 0.5f) << '\n';
}