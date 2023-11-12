#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> s;
list<char> output;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	int seq = 1;

	for (int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;

		while (s.empty() || s.top() < n)
		{
			s.push(seq++);
			output.push_back('+');
		}

		if (s.top() == n)
		{
			s.pop();
			output.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (char c : output)
		cout << c << '\n';
}