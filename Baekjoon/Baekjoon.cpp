#include <bits/stdc++.h>
using namespace std;

int N;
int a[1'000'003];
int s[1'000'003];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		s[i] = a[i];
	}
	sort(s, s + N);

	for (int i = 0; i < N; ++i)
	{
		if (s[i] != s[i + 1])
			v.push_back(s[i]);
	}

	for (int i = 0; i < N; ++i)
		cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << ' ';
}