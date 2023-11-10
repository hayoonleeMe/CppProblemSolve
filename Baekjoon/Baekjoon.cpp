#include <bits/stdc++.h>
using namespace std;

int num[10];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int mul = 1;
	for (int i = 0; i < 3; ++i)
	{
		int t; cin >> t;
		mul *= t;
	}
	string s = to_string(mul);

	for (char c : s)
		++num[c - '0'];

	for (int i = 0; i < 10; ++i)
		cout << num[i] << '\n';
}