#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
string s;
queue<char> q;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> s;

	int threshold = N + 1;
	int i = 0;
	for (char n : s)
	{
		if (n == 'I')
		{
			if (q.empty() || q.back() == 'O')
			{
				q.push(n);
				++i;

				if (i == threshold)
				{
					++ans;
					q.pop(); q.pop();
					--i;
				}
			}
			else
			{
				for (; !q.empty(); q.pop());
				q.push(n);
				i = 1;
			}
		}
		else if (n == 'O' && !q.empty())
		{
			if (q.back() == 'I')
				q.push(n);
			else
			{
				for (; !q.empty(); q.pop());
				i = 0;
			}
		}
	}

	cout << ans;
}